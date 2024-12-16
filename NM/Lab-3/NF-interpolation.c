#include <stdio.h>
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate u value
float calculateU(float u, int n) {
    float result = u;
    for (int i = 1; i < n; i++) {
        result *= (u - i);
    }
    return result;
}

int main() {
    int n;
    float x[20], y[20][20], value, u, h, result;

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input x and y values
    printf("Enter the x values: \n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
    }

    printf("Enter the y values (corresponding to each x): \n");
    for (int i = 0; i < n; i++) {
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    // Calculate the forward difference table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    // Display the forward difference table
    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%0.4f\t", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("%0.4f\t", y[i][j]);
        }
        printf("\n");
    }

    // Input the value to interpolate
    printf("\nEnter the value to interpolate: ");
    scanf("%f", &value);

    // Calculate u
    h = x[1] - x[0];
    u = (value - x[0]) / h;

    // Apply Newton Forward Interpolation Formula
    result = y[0][0];
    for (int i = 1; i < n; i++) {
        result += (calculateU(u, i) * y[0][i]) / factorial(i);
    }

    // Output the result
    printf("\nInterpolated value at x = %0.4f is %0.4f\n", value, result);

    return 0;
}
