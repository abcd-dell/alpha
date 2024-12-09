#include <stdio.h>
#define INF 9999
#define MAX 10
void dijkstra(int G[MAX][MAX], int n, int start) {
    int dist[MAX], visited[MAX] = {0}, pred[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = (G[start][i] == 0) ? INF : G[start][i];
        pred[i] = start;
    }
    dist[start] = 0;
    for (int count = 1; count < n; count++) {
        int min = INF, next = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) min = dist[next = i];
        visited[next] = 1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && G[next][i] && dist[next] + G[next][i] < dist[i]) {
                dist[i] = dist[next] + G[next][i];
                pred[i] = next;
            }
    }
    for (int i = 1; i < n; i++)
         {
            printf("\nDist to %d: %d\nPath: %d", i, dist[i], i);
            for (int j = i; (j = pred[j]) != start;)
                printf(" <- %d", j);
            printf(" <- %d", start);
        }
}
int main() {
    int G[MAX][MAX], n, start;
    printf("Enter #vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    printf("Enter start node: ");
    scanf("%d", &start);
    dijkstra(G, n, start);
    return 0;
}
