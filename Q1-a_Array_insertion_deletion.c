#include <stdio.h>

#define MAX 100

void display(int a[], int n) {
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void insert(int a[], int *n, int pos, int val) {
    int i;

    if (*n == MAX || pos < 1 || pos > *n + 1) {
        printf("Invalid position!\n");
        return;
    }

    for (i = *n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = val;
    (*n)++;
}

void delete(int a[], int *n, int pos) {
    int i;

    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++)
        a[i] = a[i + 1];

    (*n)--;
}

int main() {
    int a[MAX], n, i, choice, pos, val;

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position and value: ");
                scanf("%d%d", &pos, &val);
                insert(a, &n, pos, val);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete(a, &n, pos);
                break;

            case 3:
                display(a, n);
                break;
        }
    } while (choice != 0);

    return 0;
}
