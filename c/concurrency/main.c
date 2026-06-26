#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long counte r = 0;

pthread_mutex_t lock;

// Функция, которую будет выполнять каждый поток
void* increment_counter(void* arg) {
    int id = *(int*)arg;
    
    for (int i = 0; i < 1000000; i++) {
        // Блокируем мьютекс перед изменением общей переменной
        pthread_mutex_lock(&lock);
        
        counter++;
        
        // Разблокируем мьютекс
        pthread_mutex_unlock(&lock);
    }
    
    printf("Поток %d завершил работу\n", id);
    return NULL;
}

int main() {
    int num_threads = 4;
    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    // Инициализация мьютекса
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Ошибка инициализации мьютекса\n");
        return 1;
    }

    // Создание потоков
    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, increment_counter, &thread_ids[i]) != 0) {
            perror("Не удалось создать поток");
            return 1;
        }
    }

    // Ожидание завершения всех потоков (join)
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Удаление мьютекса
    pthread_mutex_destroy(&lock);

    printf("Финальное значение счетчика: %lld\n", counter);
    printf("Ожидаемое значение: %lld\n", (long long)num_threads * 1000000);

    return 0;
}