#include <stdio.h>

void merge(int a[], int temp[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l; i <= r; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int n) {
    int temp[100];
    int width, l, m, r;

    for (width = 1; width < n; width *= 2) {
        for (l = 0; l < n - width; l += 2 * width) {
            m = l + width - 1;
            r = l + 2 * width - 1;

            if (r >= n)
                r = n - 1;

            merge(a, temp, l, m, r);
        }
    }
}

int main(void) {
    int a[100], n, i;

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, n);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
