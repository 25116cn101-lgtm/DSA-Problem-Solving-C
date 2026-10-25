#include <stdio.h>

void towerOfHanoi(int n, char source,
                  char auxiliary, char destination) {
    if (n == 0)
        return;

    towerOfHanoi(n - 1, source, destination, auxiliary);

    printf("Move disk %d from %c to %c\n",
           n, source, destination);

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main(void) {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Enter disks between 1 and 20\n");
        return 0;
    }

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
