#include<stdio.h>
#include<unistd.h>
int main(){
    pid_t pid;
    int x=1;
    pid = fork();
    if(pid<0){
        printf("Error creating child process.\n");
    }else if(pid==0){
        printf("Child process (PID %d):x=%d\n",getpid(),++x);
    }else{
        printf("Parent process (PID %d):x=%d\n",getpid(),--x);
    }
    return 0;
    } 