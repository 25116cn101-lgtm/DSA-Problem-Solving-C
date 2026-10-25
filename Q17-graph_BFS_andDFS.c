#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void DFS(int v) {
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            DFS(i);
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int seen[MAX] = {0};
    int v, i;

    queue[rear++] = start;
    seen[start] = 1;

    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (graph[v][i] && !seen[i]) {
                seen[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main(void) {
    int e, u, v, i, start;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &e);

    if (n < 1 || n > MAX || e < 0)
        return 0;

    for (i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n)
            return 0;

        graph[u][v] = graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
        return 0;

    printf("DFS: ");
    DFS(start);

    printf("\nBFS: ");
    BFS(start);

    printf("\n");
    return 0;
}
