#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;

void BFS(int start) {
    int front = -1, rear = -1;
    int i;

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    printf("\nBFS Order: ");
    queue[++rear] = start;
    visited[start] = 1;

    while (front != rear) {
        int v = queue[++front];
        printf(" %d", v);

        for (i = 1; i <= n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf(" %d", v);

    for (i = 1; i <= n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, s, d, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            adj[i][j] = 0;

    printf("Enter edges of the matrix (%d x %d):\n", n, n);
    for (i = 1; i < n; i++) {
        scanf("%d %d", &s, &d);
        adj[s][d] = 1;
        adj[d][s] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal:\n");
    DFS(start);

    return 0;
}
