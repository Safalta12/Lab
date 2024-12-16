#include <stdio.h>

double f(double x, double y) {
    return x * y;  // This is the function f(x, y) = xy
}

int main() {
    double x = 1.0, y = 1.0;  // Initial conditions
    double h = 0.25;          // Step size
    double x_end = 2.0;       // End point for x

    printf("Solving the differential equation y' = xy using Euler's Method:\n");
    printf("Initial condition: y(1) = 1\n");
    printf("Step size: h = 0.25\n");

    while (x < x_end) {
        y = y + h * f(x, y);  // Euler's method formula
        x = x + h;            // Increment x by h
    }

    printf("The value of y(2) is: %.4f\n", y);

    return 0;
}
