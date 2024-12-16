#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 10
#define STEP_SIZE 0.1

// Function for the right-hand side of the differential equation
// dy/dx = y + x
double f(double y, double x) {
    return y + x;
}

// Function to perform the Picard iteration
double picard_iteration(double y_previous, double x, double h) {
    double integral = 0.0;
    // Approximate the integral using the trapezoidal rule
    for (double t = 0; t <= x; t += h) {
        integral += (f(y_previous, t) + f(y_previous, t + h)) * h / 2.0;
    }
    return 1.0 + integral; // y(0) = 1, so we add 1 to the result
}

int main() {
    double y0 = 1.0;  // Initial condition y(0) = 1
    double x = 0.0;   // Starting point
    double y = y0;    // Current approximation of y
    double h = STEP_SIZE; // Step size for numerical integration

    printf("Picard's Method for solving dy/dx = y + x\n");
    printf("Using initial condition y(0) = 1\n\n");

    // Perform iterations of Picard's method
    for (int i = 0; i < 7; i++) {
        y = picard_iteration(y, x, h);  // Compute the next approximation
        printf("Iteration %d: y(%.2f) = %.6f\n", i + 1, x, y);
    }

    return 0;
}
