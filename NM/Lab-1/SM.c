#include <stdio.h>
#include <math.h>
#include <conio.h>
#define f(x) (x*x*x - 3*x - 5)
#define E 0.001
int main() {
    float x1, x2, x3, f1, f2, f3;
    int iteration = 0;
    printf("Enter two initial guesses: ");
    scanf("%f%f", &x1, &x2);
    f1 = f(x1);
    f2 = f(x2);
    if (fabs(f1) < E) {
        printf("%f is a root found in iteration %d", x1,iteration);
        return 0;
    } else if (fabs(f2) < E) {
        printf("%f is a root found in iteration %d", x2,iteration);
        return 0;
    }
    do {
        x3 = x2 - f2 * ((x2 - x1) / (f2 - f1));
        f3 = f(x3);
        if (fabs((x3 - x2) / x3) <= E) {
            printf("The root is %f found in iteration %d", x3,iteration);
            break;
        } else {
            x1 = x2;
            x2 = x3;
            f1 = f2;
            f2 = f3;
            iteration++;
        }
    } while (1); 
    getch();
    return 0;
}
