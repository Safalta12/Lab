#include <stdio.h>
#include <math.h>

// Define the function representing the differential equation y' = x^2 + y^2
double f(double x, double y) {
    return x*x + y*y;
}

int main() {
    // Initial conditions
    double x = 0.0;  // Start point
    double y = 0.0;  // Initial value of y
    double h = 0.2;  // Step size
    double x_end = 1.0;  // End point (you can change it as needed)

    // Print the initial condition
    printf("x = %.2f, y = %.4f\n", x, y);

    // Loop for Heun's method (iterating until we reach x_end)
    while (x < x_end) {
        // Compute the value of y' at the current point
        double k1 = f(x, y);
        
        // Predict the value of y at the next point
        double y_predict = y + h * k1;
        
        // Compute the value of y' at the predicted point
        double k2 = f(x + h, y_predict);
        
        // Correct the predicted value
        y = y + (h / 2.0) * (k1 + k2);
        
        // Update x
        x += h;

        // Print the current value of x and y
        printf("x = %.2f, y = %.4f\n", x, y);
    }

    return 0;
}
