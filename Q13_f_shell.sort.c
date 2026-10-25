#include <stdio.h>

void shellSort(int a[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = a[i];

            for (j = i; j >= gap && a[j - gap] > temp;
                 j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}

int main(void) {
    int a[100], n, i;

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    shellSort(a, n);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
