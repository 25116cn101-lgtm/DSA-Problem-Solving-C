#include <stdbool.h>
#include <stdlib.h>

bool validPath(int n, int** edges, int edgesSize,
               int* edgesColSize, int source, int destination) {
    int *parent = malloc(n * sizeof(int));
    int *queue = malloc(n * sizeof(int));
    int i, u, v, front = 0, rear = 0;

    if (parent == NULL || queue == NULL) {
        free(parent);
        free(queue);
        return false;
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < edgesSize; i++) {
        u = edges[i][0];
        v = edges[i][1];

        while (parent[u] != u)
            u = parent[u];

        while (parent[v] != v)
            v = parent[v];

        if (u != v)
            parent[u] = v;
    }

    u = source;
    while (parent[u] != u)
        u = parent[u];

    v = destination;
    while (parent[v] != v)
        v = parent[v];

    free(parent);
    free(queue);

    return u == v;
}
