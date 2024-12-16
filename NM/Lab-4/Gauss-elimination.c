#include <stdio.h>
#include <math.h>

#define MAX 10

void gaussElimination(float matrix[MAX][MAX], int n) {
    int i, j, k;
    float ratio;

    // Forward elimination
    for (i = 0; i < n - 1; i++) {
        if (matrix[i][i] == 0.0) {
            printf("Mathematical Error: Division by zero.\n");
            return;
        }
        for (j = i + 1; j < n; j++) {
            ratio = matrix[j][i] / matrix[i][i];
            for (k = 0; k <= n; k++) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }

    // Back substitution
    float solution[MAX];
    for (i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    // Display solution
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i + 1, solution[i]);
    }
}

int main() {
    float matrix[MAX][MAX];
    int n, i, j;

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    gaussElimination(matrix, n);

    return 0;
}
