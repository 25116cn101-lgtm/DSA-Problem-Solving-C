#include <stdio.h>

void quickSort(int a[], int n) {
    int low[100], high[100];
    int top = -1, l, h, i, j, pivot, temp;

    if (n <= 1)
        return;

    low[++top] = 0;
    high[top] = n - 1;

    while (top >= 0) {
        l = low[top];
        h = high[top--];

        pivot = a[h];
        i = l - 1;

        for (j = l; j < h; j++) {
            if (a[j] <= pivot) {
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[i + 1];
        a[i + 1] = a[h];
        a[h] = temp;

        int p = i + 1;

        if (p - 1 > l) {
            low[++top] = l;
            high[top] = p - 1;
        }

        if (p + 1 < h) {
            low[++top] = p + 1;
            high[top] = h;
        }
    }
}

int main(void) {
    int a[100], n, i;

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, n);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
