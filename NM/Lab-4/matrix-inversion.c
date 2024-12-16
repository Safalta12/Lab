#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

void getCofactor(float matrix[MAX][MAX], float temp[MAX][MAX], int p, int q, int n) {
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];

                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

float determinant(float matrix[MAX][MAX], int n) {
    if (n == 1)
        return matrix[0][0];

    float det = 0;
    float temp[MAX][MAX];
    int sign = 1;

    for (int f = 0; f < n; f++) {
        getCofactor(matrix, temp, 0, f, n);
        det += sign * matrix[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    return det;
}

void adjoint(float matrix[MAX][MAX], float adj[MAX][MAX], int n) {
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    float temp[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(matrix, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, n - 1);
        }
    }
}

int inverse(float matrix[MAX][MAX], float inverse[MAX][MAX], int n) {
    float det = determinant(matrix, n);
    if (fabs(det) < 1e-6) {
        printf("Matrix is singular and cannot have an inverse.\n");
        return 0;
    }

    float adj[MAX][MAX];
    adjoint(matrix, adj, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inverse[i][j] = adj[i][j] / det;

    return 1;
}

void multiplyMatrix(float A[MAX][MAX], float B[MAX], float result[MAX], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++) {
            result[i] += A[i][j] * B[j];
        }
    }
}

int main() {
    int n;
    float A[MAX][MAX], B[MAX], X[MAX], inv[MAX][MAX];

    printf("Enter the number of equations (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter the coefficients matrix A (size %dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%f", &A[i][j]);

    printf("Enter the constants vector B (size %dx1):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &B[i]);

    if (inverse(A, inv, n)) {
        printf("The inverse of matrix A is:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%.2f ", inv[i][j]);
            printf("\n");
        }

        multiplyMatrix(inv, B, X, n);

        printf("\nThe solution vector X is:\n");
        for (int i = 0; i < n; i++)
            printf("X[%d] = %.2f\n", i + 1, X[i]);
    }

    return 0;
}
