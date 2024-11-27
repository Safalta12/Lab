#include<stdio.h>
#include<conio.h>
int main() {
    float x[50], y[50], xp, yp = 0, p;
    int i, j, n;
    printf("Enter number of data: ");
    scanf("%d", &n);
    printf("Enter data:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
    printf("Enter interpolation point: ");
    scanf("%f", &xp);
    for (i = 0; i < n; i++) {
        p = 1; 
        for (j = 0; j < n; j++) {
            if (i != j) {
                p *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += p * y[i];
    }
    printf("Interpolated value at %.2f is %.4f.\n", xp, yp);
    getch();
    return 0;
}


