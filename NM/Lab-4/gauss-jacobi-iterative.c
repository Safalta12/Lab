#include <stdio.h>
#include <math.h>

#define MAX 10

// Function to perform Gauss-Jacobi method
void gaussJacobi(double a[MAX][MAX], double b[MAX], double x[MAX], int n, double tolerance, int maxIterations) {
    double xNew[MAX]; // To store the new values of x
    int iter = 0;
    double sum, error;

    // Initialize x array with zeros
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    // Iterative process
    do {
        for (int i = 0; i < n; i++) {
            sum = 0;

            // Calculate the sum of a[i][j] * x[j] for j != i
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += a[i][j] * x[j];
                }
            }

            // Calculate the new value of x[i]
            xNew[i] = (b[i] - sum) / a[i][i];
        }

        // Calculate the maximum error
        error = 0;
        for (int i = 0; i < n; i++) {
            error = fmax(error, fabs(xNew[i] - x[i]));
            x[i] = xNew[i];  // Update x[i] for the next iteration
        }

        iter++;

        // Display the current solution vector
        printf("Iteration %d: ", iter);
        for (int i = 0; i < n; i++) {
            printf("%0.4lf ", x[i]);
        }
        printf("\n");

    } while (error > tolerance && iter < maxIterations);

    printf("\nSolution found after %d iterations\n", iter);
    printf("Solution: ");
    for (int i = 0; i < n; i++) {
        printf("%0.4lf ", x[i]);
    }
    printf("\n");
}

int main() {
    int n;
    double tolerance;
    int maxIterations;
    
    // Input the size of the matrix
    printf("Enter the number of variables (n): ");
    scanf("%d", &n);

    double a[MAX][MAX], b[MAX], x[MAX];
    
    // Input the augmented matrix (coefficient matrix and the right-hand side)
    printf("Enter the coefficient matrix (A):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    // Input the constants (b)
    printf("Enter the constants (b):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    // Input tolerance and max iterations
    printf("Enter tolerance: ");
    scanf("%lf", &tolerance);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &maxIterations);

    // Solve the system using Gauss-Jacobi method
    gaussJacobi(a, b, x, n, tolerance, maxIterations);

    return 0;
}
