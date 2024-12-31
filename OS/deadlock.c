#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *function1();
void *function2();
pthread_mutex_t first_mutex;  // Mutex lock
pthread_mutex_t second_mutex;

int main() {
    pthread_mutex_init(&first_mutex, NULL);  // Initialize the lock
    pthread_mutex_init(&second_mutex, NULL);
    pthread_t one, two;
    pthread_create(&one, NULL, function1, NULL);  // Create thread
    pthread_create(&two, NULL, function2, NULL);
    pthread_join(one, NULL); // Wait for thread_one to complete execution
    pthread_join(two, NULL);
    printf("Threads joined\n");
    return 0;
}

void *function1() {
    pthread_mutex_lock(&first_mutex);  // Acquire first_mutex
    printf("Thread ONE acquired first_mutex\n");
    sleep(1);
    pthread_mutex_lock(&second_mutex);  // Acquire second_mutex
    printf("Thread ONE acquired second_mutex\n");
    pthread_mutex_unlock(&second_mutex);  // Release second_mutex
    printf("Thread ONE released second_mutex\n");
    pthread_mutex_unlock(&first_mutex);  // Release first_mutex
    printf("Thread ONE released first_mutex\n");
    return NULL;
}

void *function2() {
    pthread_mutex_lock(&first_mutex);  // Acquire first_mutex first
    printf("Thread TWO acquired first_mutex\n");
    sleep(1);
    pthread_mutex_lock(&second_mutex);  // Acquire second_mutex
    printf("Thread TWO acquired second_mutex\n");
    pthread_mutex_unlock(&second_mutex);  // Release second_mutex
    printf("Thread TWO released second_mutex\n");
    pthread_mutex_unlock(&first_mutex);  // Release first_mutex
    printf("Thread TWO released first_mutex\n");
    return NULL;
}
