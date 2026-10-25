#include <stdio.h>

#define MAX 10

void multiply(int a[MAX][MAX], int b[MAX][MAX],
              int c[MAX][MAX], int r1, int c1, int c2) {
    int i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            c[i][j] = 0;

            for (k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

int diagonalSum(int a[MAX][MAX], int n) {
    int i, sum = 0;

    for (i = 0; i < n; i++)
        sum += a[i][i];

    return sum;
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int r1, c1, r2, c2, i, j;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter Matrix A:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d", &r2, &c2);

    if (c1 != r2 || r1 > MAX || c1 > MAX ||
        r2 > MAX || c2 > MAX) {
        printf("Invalid matrix dimensions!\n");
        return 0;
    }

    printf("Enter Matrix B:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    multiply(a, b, c, r1, c1, c2);

    printf("Product Matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    if (r1 == c1)
        printf("Diagonal Sum of A: %d\n",
               diagonalSum(a, r1));
    else
        printf("Matrix A is not square.\n");

    return 0;
}
