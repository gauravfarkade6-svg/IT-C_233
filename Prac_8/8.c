#include <stdio.h>

#define MAX 30
int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void Union(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n, ne = 1;
    int cost[MAX][MAX];
    int i, j, a, b, u, v, mincost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;   // Replace 0 with large value
        }
    }

    for (i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nThe edges of the Minimum Cost Spanning Tree are:\n");

    while (ne < n) {
        int min = 999;
        a = -1; 
        b = -1;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        if (find(u) != find(v)) {
            printf("%d. Edge (%d -> %d) = %d\n", ne, a, b, min);
            mincost += min;
            Union(u, v);
            ne++;
        }

        cost[a][b] = cost[b][a] = 999; // Remove edge
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}

