#include <stdio.h>
#include <math.h>
#include <conio.h>
#define f(x)(x*x*x-2*x-5)
#define E 0.01
int main(){
    float x0,x1,x2,f0,f1,f2;
    int iteration=0;
    repeat:
    printf("Enter two initial guess value:");
    scanf("%f%f",&x1,&x2);
    f1=f(x1);
    f2=f(x2);
    if(f1*f2>0){
    printf("Error Initial guess.Try again!\n");
    goto repeat;
    }else if(f1*f2==0){
printf("%2f is root",x1);
    }else{
        loop:
        x0=(x1+x2)/2;
        f0=f(x0);
        if(f1*f2<0){
            x2=x0;
        }else{
            x1=x0;
        }
    if((fabs (x2-x1)/x2)<=E){
        printf("The root is %2f found in iteration %d",x0,iteration);
    }else{
        iteration++;
        goto loop;
    }
    getch();
    }
}