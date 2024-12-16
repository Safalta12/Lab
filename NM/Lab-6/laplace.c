#include <stdio.h> 
#include <math.h> 
 
#define MAX 20        // Maximum grid size 
#define TOL 1e-4      // Convergence tolerance 
#define MAX_ITER 1000 // Maximum iterations 
 
void solveLaplace(double grid[MAX][MAX], int n) { 
    int iter = 0; 
    double error; 
 
    do { 
        error = 0.0; 
        for (int i = 1; i < n - 1; i++) { 
            for (int j = 1; j < n - 1; j++) { 
                double old = grid[i][j]; 
                grid[i][j] = 0.25 * (grid[i + 1][j] + grid[i - 1][j] + grid[i][j + 1] + grid[i][j - 1]); 
                error = fmax(error, fabs(grid[i][j] - old)); 
            } 
        } 
        iter++; 
    } while (error > TOL && iter < MAX_ITER); 
 
    printf("Converged in %d iterations with error %.6f\n", iter, error); 
} 
 
int main() { 
    int n; 
    double grid[MAX][MAX] = {0}; 
 
    // Input grid size 
    printf("Enter grid size (max %d): ", MAX); 
    scanf("%d", &n); 
 
    // Input boundary conditions 
    printf("Enter boundary values for top, bottom, left, and right edges:\n"); 
    for (int i = 0; i < n; i++) 
    {scanf("%lf", &grid[0][i]);       // Top 
     scanf("%lf", &grid[n - 1][i]);   // Bottom 
     scanf("%lf", &grid[i][0]);       // Left 
     scanf("%lf", &grid[i][n - 1]); }  // Right 
 
    // Solve Laplace equation 
    solveLaplace(grid, n); 
 
    // Print final grid 
    printf("Final grid:\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            printf("%.2f ", grid[i][j]); 
        } 
        printf("\n"); 
    } 
 
    return 0; 
}