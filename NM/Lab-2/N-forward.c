#include <stdio.h>
#include<conio.h>
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i; 
    }
    return fact;
}
int main() {
    int n, i, j;
    float x[10], y[10][10], xp, h, u, result;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i][0]);
    }
    printf("Enter the value of x to interpolate: ");
    scanf("%f", &xp);
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    printf("\nForward Difference Table:\n");
    for (i = 0; i < n; i++) {
        printf("%f", x[i]);
        for (j = 0; j < n - i; j++) {
            printf("\t%f", y[i][j]);
        }
        printf("\n");
    }
    h = x[1] - x[0];            
    u = (xp - x[0]) / h;           
    result = y[0][0];             
    for (i = 1; i < n; i++) {
        float term = y[0][i];      
        for (j = 0; j < i; j++) {
            term *= (u - j);       
        }
        term /= factorial(i);    
        result += term;            
    }
    printf("\nThe interpolated value at x = %.2f is %.4f\n", xp, result);
    getch();
    return 0;
}
