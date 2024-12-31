#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int i, j;  

void *thread_function() {
    printf("Inside Thread\n");
    for (i = 0; i < 5; i++) {  // Corrected i-0 to i=0
        printf("%d\n", i);
        sleep(1);
    }
    printf("Thread Finished\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t a_thread;
    pthread_create(&a_thread, NULL, thread_function, NULL);
    printf("Thread Created\n");
    pthread_join(a_thread, NULL);
    printf("Thread Joined\n");
    printf("Inside Main Program\n");
    
    for (j = 20; j < 25; j++) {
        printf("%d\n", j);
        sleep(1);
    }

    return 0;
}
