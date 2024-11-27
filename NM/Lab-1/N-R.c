#include<stdio.h>
#include<math.h>
#include<conio.h>
#define f(x) (x*x-3*x+2)
#define g(x) (2*x-3)
#define E 0.001

int main(){
    float x0,f0,g0,x1;
    printf("Enter the initial guess value:");
    scanf("%f",&x0);
   do{
   f0=f(x0);
   g0=g(x0);
   x1=x0-(f0/g0);
   if(fabs((x1-x0)/x1)<=E){
    break;
   }
    x0=x1;
   }while(1);
    printf("The root is %f",x1);
   getch();
}


