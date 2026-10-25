#include <stdio.h>
#define MAX 100

void deleteElement(int a[], int *n, int pos) {
    int i;

    if (pos < 1 || pos > *n) {
        printf("Invalid position\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++)
        a[i] = a[i + 1];

    (*n)--;
}

int main(void) {
    int a[MAX], n, i, ch, pos;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
        return 0;

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("1.Beginning 2.End 3.Any Position\n");
    scanf("%d", &ch);

    if (ch == 1)
        pos = 1;
    else if (ch == 2)
        pos = n;
    else if (ch == 3) {
        printf("Enter position: ");
        scanf("%d", &pos);
    } else {
        return 0;
    }

    deleteElement(a, &n, pos);

    printf("Updated array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}
