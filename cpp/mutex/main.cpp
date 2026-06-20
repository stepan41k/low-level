#include <iostream>
#include <vector>
#include <thread>
#include <mutex> // Заголовочный файл для работы с мьютексами

// Общий ресурс
int counter = 0;

// Мьютекс для защиты счетчика
std::mutex mtx;

void increment(int thread_id, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // std::lock_guard — это RAII-обертка. 
        // Она блокирует мьютекс при создании и автоматически разблокирует его, 
        // когда переменная lock выходит из области видимости (даже при исключении).
        std::lock_guard<std::mutex> lock(mtx);
        
        counter++;
        
        // Если нужно вывести что-то в консоль синхронно, 
        // обычно используют тот же или отдельный мьютекс, 
        // чтобы строки от разных потоков не перемешались.
    }
    
    // После выхода из цикла lock_guard уничтожается, и мьютекс освобождается.
    std::cout << "Поток " << thread_id << " завершил работу." << std::endl;
}

int main() {
    const int num_threads = 5;     // Количество потоков
    const int iterations = 100000; // Сколько раз каждый поток прибавит единицу

    std::vector<std::thread> threads;

    // Запускаем потоки
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(increment, i, iterations);
    }

    // Ждем завершения всех потоков
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Ожидаемый результат: " << num_threads * iterations << std::endl;
    std::cout << "Фактический результат: " << counter << std::endl;

    return 0;
}