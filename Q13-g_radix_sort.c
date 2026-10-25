#include <stdio.h>

int getMax(int a[], int n) {
    int i, max = a[0];

    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

void countSort(int a[], int n, int exp) {
    int output[100], count[10] = {0};
    int i, digit;

    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        digit = (a[i] / exp) % 10;
        output[--count[digit]] = a[i];
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n) {
    int max = getMax(a, n);
    int exp;

    for (exp = 1; max / exp > 0; ) {
        countSort(a, n, exp);

        if (exp > max / 10)
            break;

        exp *= 10;
    }
}

int main(void) {
    int a[100], n, i;

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] < 0) {
            printf("Only non-negative values allowed\n");
            return 0;
        }
    }

    radixSort(a, n);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
