#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int lock = 0;

void *thread_function(void *arg)
{
    while (__sync_lock_test_and_set(&lock, 1) == 1)
    {
        printf("Thread %d is waiting for the lock\n", *(int *)arg);
       
    }
   
    printf("Thread %d has acquired the lock\n", *(int *)arg);

    printf("Thread %d is in the critical section\n", *(int *)arg);

    lock = 0;
    printf("Thread %d has released the lock\n", *(int *)arg);

    return NULL;
}

int main()
{
    pthread_t threads[5];
    int thread_args[5];
    for (int i = 0; i < 5; i++)
    {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return EXIT_SUCCESS;
}