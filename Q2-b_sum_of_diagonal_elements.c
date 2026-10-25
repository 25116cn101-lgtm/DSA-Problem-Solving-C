#include <stdio.h>
#define MAX 10

int main(void) {
    int a[MAX][MAX], n, i, j;
    int primary = 0, secondary = 0;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
        return 0;

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++) {
        primary += a[i][i];
        secondary += a[i][n - 1 - i];
    }

    printf("Primary diagonal sum: %d\n", primary);
    printf("Secondary diagonal sum: %d\n", secondary);

    printf("Total diagonal sum: %d\n",
           primary + secondary);

    return 0;
}
