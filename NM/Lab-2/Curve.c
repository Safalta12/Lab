#include <stdio.h>

int main() {
    int n, i;
    float x[100], y[100], sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    float m, c;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    for (i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    c = (sum_y - m * sum_x) / n;
    printf("\nThe fitted line is: y = %.2fx + %.2f\n", m, c);

    return 0;
}
