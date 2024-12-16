#include <stdio.h>
#include <math.h>

// Function to define the integrand
double f(double x) {
    return sin(x) + cos(x);  // Example function: sin(x) + cos(x)
}

// Gaussian Quadrature integration function
double gaussianIntegration(double (*func)(double), double a, double b, int n) {
    // Sample points and weights for 2-point and 3-point Gaussian Quadrature
    double x2[] = {-0.5773502692, 0.5773502692};  // Roots of P2(x)
    double w2[] = {1.0, 1.0};                     // Weights for P2(x)

    double x3[] = {-0.7745966692, 0.0, 0.7745966692};  // Roots of P3(x)
    double w3[] = {0.5555555556, 0.8888888889, 0.5555555556};  // Weights for P3(x)

    double sum = 0.0;
    double midpoint = (a + b) / 2.0;
    double halfLength = (b - a) / 2.0;

    if (n == 2) {
        // 2-point Gaussian Quadrature
        for (int i = 0; i < 2; i++) {
            double x = midpoint + halfLength * x2[i];
            sum += w2[i] * func(x);
        }
    } else if (n == 3) {
        // 3-point Gaussian Quadrature
        for (int i = 0; i < 3; i++) {
            double x = midpoint + halfLength * x3[i];
            sum += w3[i] * func(x);
        }
    } else {
        printf("Gaussian Quadrature with %d points is not supported.\n", n);
        return 0.0;
    }

    return sum * halfLength;  // Scale by the half-length of the interval
}

int main() {
    double a, b;  // Limits of integration
    int n;        // Number of points for Gaussian Quadrature (2 or 3)

    // Input the limits of integration
    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);

    // Input the number of points
    printf("Enter the number of points for Gaussian Quadrature (2 or 3): ");
    scanf("%d", &n);

    // Perform the Gaussian Quadrature
    double result = gaussianIntegration(f, a, b, n);

    // Output the result
    if (result != 0.0) {
        printf("The integral of the function from %.2f to %.2f is: %.6f\n", a, b, result);
    }

    return 0;
}
