#include <stdio.h>
#include <math.h>

// Function to calculate the value of the integrand
double f(double x) {
    return x*x*x+1; // Example function, replace it as needed
}

// Function to calculate the integral using Simpson's 3/8 Rule
double simpsonsThreeEighthsRule(double (*func)(double), double a, double b, int n) {
    // Ensure n is a multiple of 3
    // if (n % 3 != 0) {
    //     printf("Error: Number of subintervals (n) must be a multiple of 3.\n");
    //     return -1;
    // }

    double h = (b - a) / n;  // Step size
    double sum = func(a) + func(b);  // Initial sum with endpoints

    // Calculate the sum of terms
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * func(x);  // Coefficient for terms divisible by 3
        } else {
            sum += 3 * func(x);  // Coefficient for other terms
        }
    }

    // Final integral calculation
    sum *= (3 * h / 8);

    return sum;
}

int main() {
    double a, b;  // Limits of integration
    int n;        // Number of subintervals

    // Input the limits of integration and number of subintervals
    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals n : ");
    scanf("%d", &n);

    // Validate input
    // if (n % 3 != 0) {
    //     printf("Error: Number of subintervals must be a multiple of 3.\n");
    //     return 1;
    // }

    // Calculate the integral using Simpson's 3/8 Rule
    double result = simpsonsThreeEighthsRule(f, a, b, n);

    // Output the result
    if (result != -1) {
        printf("The integral of the function from %.2f to %.2f is: %.6f\n", a, b, result);
    }

    return 0;
}
