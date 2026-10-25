#include <stdio.h>
#define MAX 100

void insert(int a[], int *n, int pos, int val) {
    int i;

    if (*n >= MAX || pos < 1 || pos > *n + 1) {
        printf("Invalid position\n");
        return;
    }

    for (i = *n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = val;
    (*n)++;
}

void display(int a[], int n) {
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main(void) {
    int a[MAX], n, i, ch, pos, val;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 0 || n >= MAX)
        return 0;

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("1.Beginning 2.End 3.Any Position\n");
    scanf("%d", &ch);

    if (ch == 1)
        pos = 1;
    else if (ch == 2)
        pos = n + 1;
    else if (ch == 3) {
        printf("Enter position: ");
        scanf("%d", &pos);
    } else {
        return 0;
    }

    printf("Enter value: ");
    scanf("%d", &val);

    insert(a, &n, pos, val);
    display(a, n);

    return 0;
}
