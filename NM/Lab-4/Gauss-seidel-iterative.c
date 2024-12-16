#include <stdio.h>
#include <math.h>

#define N 3  // Number of variables

// Function to perform the Gauss-Seidel iteration
void gaussSeidel(double A[N][N], double B[N], double X[N], int maxIterations, double tolerance) {
    double X_new[N];
    int i, j, k;
    double sum, error;

    // Initialize the solution vector with zeros
    for (i = 0; i < N; i++) {
        X[i] = 0.0;
    }

    // Perform iterations
    for (k = 0; k < maxIterations; k++) {
        error = 0.0;

        // Update each variable in X
        for (i = 0; i < N; i++) {
            sum = B[i];
            for (j = 0; j < N; j++) {
                if (i != j) {
                    sum -= A[i][j] * X[j];
                }
            }
            X_new[i] = sum / A[i][i];

            // Calculate error (difference between old and new value of X[i])
            error = fmax(error, fabs(X_new[i] - X[i]));
        }

        // Copy the new values of X to X
        for (i = 0; i < N; i++) {
            X[i] = X_new[i];
        }

        // Check for convergence (if error is below tolerance, stop)
        if (error < tolerance) {
            printf("Converged after %d iterations.\n", k+1);
            break;
        }
    }

    if (k == maxIterations) {
        printf("Max iterations reached without convergence.\n");
    }
}

// Function to print the solution
void printSolution(double X[N]) {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("X[%d] = %.6f\n", i, X[i]);
    }
}

int main() {
    // Coefficient matrix A
    double A[N][N] = {
        {10, 2, 1},
        {2, 20, -2},
        {-2, 3, 10}
    };

    // Constant matrix B
    double B[N] = {9, -44, 22};

    // Solution vector X (initial guess is 0)
    double X[N];

    int maxIterations = 5;  // Maximum number of iterations
    double tolerance = 2;  // Convergence tolerance

    // Call Gauss-Seidel method
    gaussSeidel(A, B, X, maxIterations, tolerance);

    // Print the solution
    printSolution(X);

    return 0;
}
