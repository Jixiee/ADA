//Depth First Search
#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
void createGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int edges) {
    int u, v;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u, v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For an undirected graph
    }
}
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], bool visited[MAX_VERTICES], int vertices, int vertex) {
    printf("%d ", vertex);
    visited[vertex] = true;
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, visited, vertices, i);
        }
    }
}
int main() {
    int vertices, edges;
    int graph[MAX_VERTICES][MAX_VERTICES];
    bool visited[MAX_VERTICES];
    printf("------------------------------------------");
    printf("\nName=ABC \nEn No.=XYZ");
    printf("\n------------------------------------------\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }
    createGraph(graph, vertices, edges);
    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    printf("Depth-First Search starting from vertex %d: ", startVertex);
    DFS(graph, visited, vertices, startVertex);
    printf("\n");
    printf("------------------------------------------");
    return 0;
}
