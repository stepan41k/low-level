#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

int counter = 0;

std::mutex mtx;

void increment(int thread_id, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        
        counter++;
    }
    
    std::cout << "Поток " << thread_id << " завершил работу." << std::endl;
}

int main() {
    const int num_threads = 5;    
    const int iterations = 100000;

    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(increment, i, iterations);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Ожидаемый результат: " << num_threads * iterations << std::endl;
    std::cout << "Фактический результат: " << counter << std::endl;

    return 0;
}