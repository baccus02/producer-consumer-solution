#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Assume that buffer size is 2
#define BUFFER_SIZE 2

// Semaphores and mutex lock
sem_t full, empty;
pthread_mutex_t mutexLock;

int buffer[BUFFER_SIZE] = {0};
int count = 0;

void* producer(void* arg) {
    int item;
    for (int i = 0; i < 10; ++i) {
        // Produce an item
        item = i;

        // Wait if there is no empty slot
        sem_wait(&empty);

        // Lock the mutex before putting the item in the buffer
        pthread_mutex_lock(&mutexLock);
        buffer[count++] = item;
        std::cout << "Produced: " << item << std::endl;

        // Unlock the mutex
        pthread_mutex_unlock(&mutexLock);

        // Signal that there is a full slot
        sem_post(&full);

        // Sleep is added for output readability
        sleep(1);
    }

    return nullptr;
}

int main() {
    pthread_t prod;
    
    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    
    // Initialize mutex lock
    pthread_mutex_init(&mutexLock, nullptr);
    
    // Create producer thread
    pthread_create(&prod, nullptr, producer, nullptr);
    
    // Join thread (though in a real case, you might want to join this in the main thread)
    pthread_join(prod, nullptr);
    
    // Cleanup semaphores and mutex lock
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutexLock);
    
    return 0;
}
