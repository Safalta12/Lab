#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

// Semaphores
sem_t mutex;
sem_t full;
sem_t empty;

// Shared resource
int x = 0;

// Function to produce an item
void producer() {
    // Wait for empty slot
    sem_wait(&empty);

    // Acquire mutex
    sem_wait(&mutex);

    // Produce item
    x++;
    printf("\nProducer produces item %d", x);

    // Release mutex
    sem_post(&mutex);

    // Signal full slot
    sem_post(&full);
}

// Function to consume an item
void consumer() {
    // Wait for full slot
    sem_wait(&full);

    // Acquire mutex
    sem_wait(&mutex);

    if (x > 0) {
        printf("\nConsumer consumes item %d", x);
        x--;
    }

    // Release mutex
    sem_post(&mutex);

    // Signal empty slot
    sem_post(&empty);
}

// Main function
int main() {
    int n;

    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 10);

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            // Destroy semaphores
            sem_destroy(&mutex);
            sem_destroy(&full);
            sem_destroy(&empty);
            exit(0);
        default:
            printf("Invalid choice! Please try again.");
        }
    }

    return 0;
}
