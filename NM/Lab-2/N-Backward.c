#include <stdio.h>
#include <math.h>
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n,i,j;
    float x[20], y[20][20], xp, h, u, result;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the x values and corresponding y values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }
    printf("Enter the value of x to find y: ");
    scanf("%f", &xp);
    for ( j = 1; j < n; j++) {
        for (i = n - 1; i >= j; i--) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }
    printf("\nBackward Difference Table:\n");
    for ( i = 0; i < n; i++) {
        printf("x[%d] = %.2f ", i, x[i]);
        for (j = 0; j <= i; j++) {
            printf("%10.2f ", y[i][j]);
        }
        printf("\n");
    }
    h = x[1] - x[0];
    u = (xp - x[n - 1]) / h;
    result = y[n - 1][0]; 
    for (i = 1; i < n; i++) {
        float term = 1.0;
        for ( j = 0; j < i; j++) {
            term *= (u + j);
        }
        term *= y[n - 1][i] / factorial(i);
        result += term;
    }
    printf("\nThe interpolated value at x = %.2f is y = %.4f\n", xp, result);
    return 0;
}
