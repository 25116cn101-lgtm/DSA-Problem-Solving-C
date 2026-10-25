#include <stdio.h>
#define MAX 10

int main(void) {
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int r1, c1, r2, c2, i, j, k;

    printf("Enter rows and columns of A: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns of B: ");
    scanf("%d%d", &r2, &c2);

    if (r1 < 1 || r1 > MAX ||
        c1 < 1 || c1 > MAX ||
        r2 < 1 || r2 > MAX ||
        c2 < 1 || c2 > MAX || c1 != r2) {
        printf("Invalid matrix dimensions\n");
        return 0;
    }

    printf("Enter matrix A:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter matrix B:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            c[i][j] = 0;

            for (k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Product matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%d ", c[i][j]);

        printf("\n");
    }

    return 0;
}
