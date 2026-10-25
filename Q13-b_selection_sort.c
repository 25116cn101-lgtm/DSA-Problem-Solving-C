#include <stdio.h>

void selectionSort(int a[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main(void) {
    int a[100], n, i;

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    selectionSort(a, n);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
