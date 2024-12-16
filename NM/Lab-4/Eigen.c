#include <stdio.h>
#include <math.h>

#define N 3  // Size of the matrix

// Function to multiply matrix with vector
void multiplyMatrixWithVector(double matrix[N][N], double vector[N], double result[N]) {
    for (int i = 0; i < N; i++) {
        result[i] = 0;
        for (int j = 0; j < N; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

// Function to find the norm (magnitude) of a vector
double vectorNorm(double vector[N]) {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += vector[i] * vector[i];
    }
    return sqrt(sum);
}

// Function to normalize a vector
void normalizeVector(double vector[N]) {
    double norm = vectorNorm(vector);
    for (int i = 0; i < N; i++) {
        vector[i] /= norm;
    }
}

// Function to perform power iteration to find the largest eigenvalue and eigenvector
void powerIteration(double matrix[N][N], double eigenvector[N], double *eigenvalue, int iterations) {
    // Start with a random initial guess for eigenvector
    for (int i = 0; i < N; i++) {
        eigenvector[i] = 1.0; // Simple starting guess
    }

    // Perform power iteration
    double newEigenvector[N];
    for (int iter = 0; iter < iterations; iter++) {
        // Multiply matrix with the current eigenvector
        multiplyMatrixWithVector(matrix, eigenvector, newEigenvector);
        
        // Find the new eigenvalue as the ratio of the magnitude of new vector and the old vector
        *eigenvalue = vectorNorm(newEigenvector);
        
        // Normalize the new eigenvector
        normalizeVector(newEigenvector);

        // Copy the new eigenvector to the original eigenvector
        for (int i = 0; i < N; i++) {
            eigenvector[i] = newEigenvector[i];
        }
    }
}

int main() {
    // Input matrix (for example, a 3x3 matrix)
    double matrix[N][N] = {
        {1, 6, 1},
        {1, 2, 0},
        {0, 0, 3}
    };

    double eigenvector[N];
    double eigenvalue;

    // Perform power iteration to find the largest eigenvalue and eigenvector
    int iterations = 8;
    powerIteration(matrix, eigenvector, &eigenvalue, iterations);

    // Output the results
    printf("Largest Eigenvalue: %lf\n", eigenvalue);
    printf("Corresponding Eigenvector: \n");
    for (int i = 0; i < N; i++) {
        printf("%lf ", eigenvector[i]);
    }
    printf("\n");

    return 0;
}
