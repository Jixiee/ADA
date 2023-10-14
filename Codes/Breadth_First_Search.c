//Implementation of Breadth First Search in c 
#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 10
#define INF 999999
int minDistance(int dist[], bool visited[], int vertices) {
    int min = INF, min_index;
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int dist[], int parent[], int vertices, int source) {
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < vertices; i++) {
        if (i != source) {
            printf("%d -> %d\t%d\t\t%d", source, i, dist[i], source);
            int j = i;
            while (parent[j] != source) {
                printf(" -> %d", parent[j]);
                j = parent[j];
            }
            printf(" -> %d\n", i);
        }
    }
}
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int source) {
    int dist[vertices];
    bool visited[vertices];
    int parent[vertices];
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[source] = 0;
    parent[source] = -1;
    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);
        visited[u] = true;
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, vertices, source);
}
int main() {
    int vertices, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(graph, vertices, source);
    return 0;
}
