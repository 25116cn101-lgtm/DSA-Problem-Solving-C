#include <stdio.h>

int linearSearch(int a[], int n, int key) {
    int i;

    for (i = 0; i < n; i++)
        if (a[i] == key)
            return i;

    return -1;
}

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(void) {
    int a[100], n, i, key;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
        return 0;

    printf("Enter sorted array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter search key: ");
    scanf("%d", &key);

    printf("Linear Search Index: %d\n",
           linearSearch(a, n, key));

    printf("Binary Search Index: %d\n",
           binarySearch(a, n, key));

    return 0;
}
