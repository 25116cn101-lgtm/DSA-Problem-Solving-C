#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int parent[100], rankSet[100];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return 0;

    if (rankSet[a] < rankSet[b]) {
        parent[a] = b;
    } else if (rankSet[a] > rankSet[b]) {
        parent[b] = a;
    } else {
        parent[b] = a;
        rankSet[a]++;
    }

    return 1;
}

int compare(const void *a, const void *b) {
    const struct Edge *x = a;
    const struct Edge *y = b;

    return (x->w > y->w) - (x->w < y->w);
}

int main(void) {
    struct Edge edges[4950];
    int n, m, i, count = 0, total = 0;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    if (n < 1 || n > 100 ||
        m < 0 || m > 4950)
        return 0;

    for (i = 0; i < m; i++)
        scanf("%d%d%d", &edges[i].u,
              &edges[i].v, &edges[i].w);

    for (i = 0; i < n; i++) {
        parent[i] = i;
        rankSet[i] = 0;
    }

    qsort(edges, m, sizeof(struct Edge), compare);

    for (i = 0; i < m && count < n - 1; i++) {
        if (edges[i].u < 0 || edges[i].u >= n ||
            edges[i].v < 0 || edges[i].v >= n)
            return 0;

        if (unite(edges[i].u, edges[i].v)) {
            printf("%d -- %d : %d\n",
                   edges[i].u, edges[i].v, edges[i].w);

            total += edges[i].w;
            count++;
        }
    }

    if (count != n - 1)
        printf("Graph is disconnected; no spanning tree\n");
    else
        printf("MST weight: %d\n", total);

    return 0;
}
