#include <stdio.h>
#include <math.h>
#define f(x) (sqrt(5+x)) 
#define E 0.001

int main(){
    float x0, x1;
    int iteration = 0;
    
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    
    do {
        x1 = f(x0);
        iteration++;
        
        if(fabs(x1 - x0) <= E) {
            printf("The root is %f found in iteration %d\n", x1, iteration);
            break;
        }
        
        x0 = x1;
    } while(1);
    
    return 0;
}
	