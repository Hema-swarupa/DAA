#include <stdio.h>
#include <limits.h>
#define MAX 100
int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];
    int visited[MAX];
    // Initialize distances and visited
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    // Main loop
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}
int main() {
    int V, E;
    int graph[MAX][MAX] = {0};
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;   // directed graph
        // graph[v][u] = w; // uncomment for undirected
    }
    int src;
    scanf("%d", &src);
    dijkstra(graph, V, src);
    return 0;
}