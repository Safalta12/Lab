#include <stdio.h>
#define MAX 10 // Maximum number of variables

void gaussJordan(float a[MAX][MAX], int n) {
    int i, j, k;
    float temp;

    // Perform Gauss-Jordan elimination
    for (i = 0; i < n; i++) {
        // Make the diagonal element 1
        temp = a[i][i];
        for (j = 0; j <= n; j++) {
            a[i][j] /= temp;
        }

        // Make all other elements in the column 0
        for (j = 0; j < n; j++) {
            if (j != i) {
                temp = a[j][i];
                for (k = 0; k <= n; k++) {
                    a[j][k] -= temp * a[i][k];
                }
            }
        }
    }

    // Display the results
    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i + 1, a[i][n]);
    }
}

int main() {
    float a[MAX][MAX];
    int n, i, j;

    // Input number of equations
    printf("Enter the number of variables: ");
    scanf("%d", &n);

    // Input the augmented matrix
    printf("Enter the augmented matrix (including the constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Solve using Gauss-Jordan method
    gaussJordan(a, n);

    return 0;
}
