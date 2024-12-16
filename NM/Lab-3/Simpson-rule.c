#include <stdio.h>
#include <math.h>

// Function to calculate the value of the integrand
double f(double x) {
    return 1/(1+x*x);  // Example: sin(x) + cos(x)
}

// Function to calculate the integral using Simpson's 1/3 Rule
double simpsonsRule(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;  // Step size
    double sum = func(a) + func(b);  // Sum of first and last terms

    // Sum odd-indexed terms
    for (int i = 1; i < n; i += 2) {
        sum += 4 * func(a + i * h);
    }

    // Sum even-indexed terms
    for (int i = 2; i < n; i += 2) {
        sum += 2 * func(a + i * h);
    }

    // Multiply by step size and divide by 3
    sum *= (h / 3.0);

    return sum;
}

int main() {
    double a, b;  // Limits of integration
    int n;         // Number of subintervals

    // Input the limits of integration and number of subintervals
    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals n: ");
    scanf("%d", &n);


    // Calculate the integral using Simpson's 1/3 Rule
    double result = simpsonsRule(f, a, b, n);

    // Output the result
    printf("The integral of the function from %.2f to %.2f is: %.6f\n", a, b, result);

    return 0;
}
