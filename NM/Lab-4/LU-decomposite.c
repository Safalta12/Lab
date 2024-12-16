#include <stdio.h>
#include <math.h>

#define N 3 // Dimension of the matrix (change as needed)

// Function to perform LU decomposition
void luDecomposition(double A[N][N], double L[N][N], double U[N][N]) {
    for (int i = 0; i < N; i++) {
        // Upper triangular matrix U
        for (int k = i; k < N; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        // Lower triangular matrix L
        for (int k = i; k < N; k++) {
            if (i == k) {
                L[i][i] = 1; // Diagonal of L is 1
            } else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

// Function to perform forward substitution (L * y = b)
void forwardSubstitution(double L[N][N], double b[N], double y[N]) {
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum);
    }
}

// Function to perform backward substitution (U * x = y)
void backwardSubstitution(double U[N][N], double y[N], double x[N]) {
    for (int i = N - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < N; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }
}

int main() {
    double A[N][N] = {
        {3, 2, 1},
        {2, 3, 2},
        {1, 2, 3}
    };

    double b[N] = {10, 14, 14};
    double L[N][N] = {0};
    double U[N][N] = {0};
    double y[N] = {0};
    double x[N] = {0};

    // Perform LU decomposition
    luDecomposition(A, L, U);

    // Solve L * y = b (Forward Substitution)
    forwardSubstitution(L, b, y);

    // Solve U * x = y (Backward Substitution)
    backwardSubstitution(U, y, x);

    // Print the solution
    printf("The solution is:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.2f\n", i, x[i]);
    }

    return 0;
}
