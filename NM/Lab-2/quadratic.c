#include <stdio.h>

int main() {
    int n,i;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];
    float sum_x = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0;
    float sum_y = 0, sum_xy = 0, sum_x2y = 0;

    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i); 
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
         scanf("%f", &y[i]);
    }

    for ( i = 0; i < n; i++) {
        sum_x += x[i]; 
        sum_x2 += x[i] * x[i];
        sum_x3 += x[i] * x[i] * x[i];
        sum_x4 += x[i] * x[i] * x[i] * x[i];
        sum_y += y[i]; 
        sum_xy += x[i] * y[i];
        sum_x2y += x[i] * x[i] * y[i];
    }

    // Calculate determinant D and the coefficients a, b, 6c
    float D = sum_x4 * sum_x2 * n + sum_x3 * sum_x * sum_x2 + sum_x2 * sum_x * sum_x3 -
              sum_x2 * sum_x2 * sum_x2 - sum_x4 * sum_x * sum_x - sum_x3 * sum_x3 * n;
    float Da = sum_x2 * sum_x2y * n + sum_xy * sum_x * sum_x3 + sum_x * sum_x2 * sum_x2y -
               sum_x2 * sum_x2 * sum_y - sum_x4 * sum_xy * n - sum_x3 * sum_x * sum_x2y;
    float Db = sum_x4 * sum_xy * n + sum_x3 * sum_x * sum_x2y + sum_x2 * sum_x2 * sum_y -
               sum_x4 * sum_x2 * sum_y - sum_x3 * sum_x3 * n - sum_x2 * sum_x * sum_x2y;
    float Dc = sum_x4 * sum_x2y * sum_x - sum_x3 * sum_x3 * sum_y - sum_x2 * sum_x * sum_x2y +
               sum_x2 * sum_x2 * sum_xy + sum_x3 * sum_x2 * sum_y - sum_x2 * sum_x * sum_x3;

    float a = Da / D, b = Db / D, c = Dc / D;
    printf("The fitted quadratic polynomial is: y = %.4fx^2 + %.4fx + %.4f\n", a, b, c);
    
    return 0;
}
