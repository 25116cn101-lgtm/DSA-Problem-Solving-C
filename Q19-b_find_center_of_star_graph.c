
#include <stdio.h>

int findCenter(int edges[][2], int n) {
    if (edges[0][0] == edges[1][0] ||
        edges[0][0] == edges[1][1])
        return edges[0][0];

    return edges[0][1];
}

int main(void) {
    int edges[100][2], n, i;

    printf("Enter number of edges: ");
    scanf("%d", &n);

    if (n < 2 || n > 100)
        return 0;

    printf("Enter edges:\n");
    for (i = 0; i < n; i++)
        scanf("%d%d", &edges[i][0], &edges[i][1]);

    printf("Center: %d\n", findCenter(edges, n));

    return 0;
}
