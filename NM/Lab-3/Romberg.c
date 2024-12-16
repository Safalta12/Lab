#include <stdio.h>
#include <math.h>

// Function to calculate the value of the integrand
double f(double x) {
    return log (x); // Example function: sin(x) + cos(x)
}

// Function to perform the trapezoidal rule
double trapezoidalRule(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;  // Step size
    double sum = (func(a) + func(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        sum += func(a + i * h);
    }

    return sum * h;
}

// Function to perform Romberg Integration
double rombergIntegration(double (*func)(double), double a, double b, int maxOrder) {
    double R[maxOrder][maxOrder]; // Romberg table

    // Compute R[0][0] using the trapezoidal rule
    R[0][0] = trapezoidalRule(func, a, b, 1);

    // Fill the Romberg table
    for (int i = 1; i < maxOrder; i++) {
        // Compute the trapezoidal rule for 2^i intervals
        int n = 1 << i; // 2^i
        R[i][0] = trapezoidalRule(func, a, b, n);

        // // Use Richardson extrapolation to refine results
        // for (int k = 1; k <= i; k++) {
        //     R[i][k] = (pow(4, k) * R[i][k - 1] - R[i - 1][k - 1]) / (pow(4, k) - 1);
        // }
    }

    // The most accurate result is at R[maxOrder-1][maxOrder-1]
    return R[maxOrder - 1][maxOrder - 1];
}

int main() {
    double a, b;  // Limits of integration
    int maxOrder; // Maximum order for Romberg Integration

    // Input the limits of integration and maximum order
    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);
    printf("Enter the maximum order for Romberg Integration: ");
    scanf("%d", &maxOrder);

    // Calculate the integral using Romberg Integration
    double result = rombergIntegration(f, a, b, maxOrder);

    // Output the result
    printf("The integral of the function from %.2f to %.2f is: %.8f\n", a, b, result);

    return 0;
}
