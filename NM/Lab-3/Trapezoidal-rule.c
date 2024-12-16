#include <stdio.h>
#include <math.h>

// Function to be integrated
float f(float x) {
    return 1/(1+x*x); // Example: f(x) = x^2
}

// Function to calculate integration using Trapezoidal Rule
float trapezoidal_rule(float a, float b, int n) {
    float h = (b - a) / n; // Step size
    float sum = f(a) + f(b); // First and last terms

    for (int i = 1; i < n; i++) {
        float x = a + i * h;
        sum += 2 * f(x); // Intermediate terms
    }

    return (h / 2) * sum;
}

int main() {
    float a, b; // Limits of integration
    int n;      // Number of subintervals

    // Input
    printf("Enter the lower limit of integration (a): ");
    scanf("%f", &a);

    printf("Enter the upper limit of integration (b): ");
    scanf("%f", &b);

    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    // Ensure n > 0
    if (n <= 0) {
        printf("Number of subintervals must be positive.\n");
        return 1;
    }

    // Calculate and display result
    float result = trapezoidal_rule(a, b, n);
    printf("\nThe approximate value of the integral is: %0.4f\n", result);

    return 0;
}
