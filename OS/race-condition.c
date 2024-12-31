#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
int shared=1;
void *fun1()
{
    int x;
    x=shared;
    x++;
    printf("Local updation by Thread1:%d\n",x);
    sleep(1);
    shared=x;
    printf("Value of shared variable updated by Thread1 is :%d\n",shared);
}
void *fun2(){
    int y;
    y=shared;
     y--;
    printf("Local updation by Thread2:%d\n",y);
    sleep(1);
    shared=y;
    printf("Value of shared variable updated by Thread2 is: %d\n",shared);
}
int main()
{
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,fun1,NULL);
    pthread_create(&thread2,NULL,fun2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("Final value of shared is %d\n",shared);
}