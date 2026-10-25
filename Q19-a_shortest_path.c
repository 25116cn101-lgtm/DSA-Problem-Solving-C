#include <stdio.h>

#define MAX 100
#define INF 1000000000

int main(void) {
    int graph[MAX][MAX];
    int dist[MAX], visited[MAX] = {0};
    int n, m, i, j, u, v, w, source;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    if (n < 1 || n > MAX || m < 0)
        return 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);

        if (u < 0 || u >= n || v < 0 || v >= n ||
            w < 0)
            return 0;

        if (w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= n)
        return 0;

    for (i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    for (i = 0; i < n; i++) {
        int minDist = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] <= INF - graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d: Unreachable\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }

    return 0;
}
