#include <stdio.h>

#define h 0.1  // Step size
#define x0 0.0 // Initial value of x
#define y0 1.0 // Initial value of y

// Function that represents the differential equation dy/dx = x + y
double f(double x, double y) {
    return x + y;
}

// Runge-Kutta method of 4th order to solve dy/dx = f(x, y)
void rungeKutta(double x, double y, double endX) {
    double k1, k2, k3, k4;
    
    printf("x = %.2f, y = %.4f\n", x, y); // Print initial values
    
    // Iterate from x = x0 to x = endX
    while (x < endX) {
        k1 = h * f(x, y);
        k2 = h * f(x + h/2, y + k1/2);
        k3 = h * f(x + h/2, y + k2/2);
        k4 = h * f(x + h, y + k3);

        // Update y using the weighted sum of k1, k2, k3, and k4
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;

        // Update x
        x = x + h;

        printf("x = %.2f, y = %.4f\n", x, y); // Print the current values of x and y
    }
}

int main() {
    double endX = 0.4; // We will solve up to x = 1.0 (or any desired endpoint)

    // Initial values
    double x = x0, y = y0;

    // Call the Runge-Kutta method to solve the equation
    rungeKutta(x, y, endX);

    return 0;
}
