#include <stdio.h>
#include <math.h>
#define f(x) (x*x-3*x+2)  
#define E 0.01

int main(){
    float x0, x1, x2, f0, f1, f2;
    int iteration = 0;

    repeat:
    printf("Enter two initial guesses: ");
    scanf("%f%f", &x1, &x2);
    f1 = f(x1);
    f2 = f(x2);
    
    if(f1 * f2 > 0) {
        printf("Error initial guess. Try again!\n");
        goto repeat; 
    } else if(f1 == 0) {
        printf("%2f is root found in iteration %d", x1, iteration);
    } else if(f2 == 0) {
        printf("%2f is root found in iteration %d", x2, iteration);
    } else {
        loop:
        iteration++;
        x0 = x1 - f1 * ((x2 - x1) / (f2 - f1));
        f0 = f(x0);

        if(fabs(f0) < E) {
            printf("The root is %2f found in iteration %d\n", x0, iteration);
        } else {
            if(f1 * f0 < 0) {
                x2 = x0;
                f2 = f0;
            } else {
                x1 = x0;
                f1 = f0;
            }
            goto loop;
        }
    }
    return 0;
}
