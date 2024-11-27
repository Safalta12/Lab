#include<stdio.h>
#include<conio.h>
int main() {
    float v = 0, p, xv, x[10], fx[10], a[10];
    int i, j, n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the value of x for interpolation: ");
    scanf("%f", &xv);
    for (i = 0; i < n; i++) {
        printf("Enter the value of x and fx at i = %d: ", i);
        scanf("%f %f", &x[i], &fx[i]);
    }
    for (i = 0; i < n; i++) {
        a[i] = fx[i];
    }
    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            a[j] = (a[j] - a[j - 1]) / (x[j] - x[j - i]);
        }
    }
    v = a[0];
    for (i = 1; i < n; i++) {
        p = 1;
        for (j = 0; j < i; j++) {
            p *= (xv - x[j]);
        }
        v += a[i] * p;
    }
    printf("Interpolated value = %f\n", v);
    getch(); 
    return 0;
}
