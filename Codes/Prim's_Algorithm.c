// Write a program to implement prim's algorithm using greedy approach
#include <stdio.h>
#include <limits.h>

#define V 100

int minKey(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void printMST(int parent[], int graph[V][V], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V], int vertices) {
    int parent[V];
    int key[V];
    int mstSet[V];
    
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = 1;
        
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    printMST(parent, graph, vertices);
}

int main() {
    int vertices;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    int graph[V][V];
    
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Minimum Spanning Tree (MST) using Prim's Algorithm:\n");
    primMST(graph, vertices);
    
    return 0;
}
