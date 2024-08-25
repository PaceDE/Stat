#include<stdio.h>

#define INFINITY 999

void dijkstra(int n, int v, int cost[10][10], int dist[100]) {
    int i, u, count, w, flag[10], min;

    for (i = 1; i <= n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }

    count = 2;
    while (count <= n) {
        min = INFINITY;
        for (w = 1; w <= n; w++) {
            if (dist[w] < min && !flag[w]) {
                min = dist[w];
                u = w;
            }
        }
        flag[u] = 1;
        count++;
        for (w = 1; w <= n; w++) {
            if ((dist[u] + cost[u][w] < dist[w]) && !flag[w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    int n, v, i, j, cost[10][10], dist[100];
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INFINITY;
            }
        }
    }
    printf("\nEnter the source node: ");
    scanf("%d", &v);
    dijkstra(n, v, cost, dist);
    printf("\nShortest paths:\n");
    for (i = 1; i <= n; i++) {
        if (i != v) {
            printf("%d to %d: Distance = %d\n", v, i, dist[i]);
        }
    }
    return 0;
}
