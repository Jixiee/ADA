//Kruskal's Algorithm
#include <stdio.h>
#define MAX 30
typedef struct edge {
    int u, v, w;
} edge;

typedef struct edge_list {
    edge data[MAX];
    int n;
} edge_list;

edge_list elist;
int Graph[MAX][MAX], n;
edge_list spanlist;
void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();
void kruskalAlgo() {
    int belongs[MAX], i, j, cno1, cno2;
    elist.n = 0;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++) {
            if (Graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
        }

    sort();
    for (i = 0; i < n; i++)
        belongs[i] = i;
    spanlist.n = 0;
    for (i = 0; i < elist.n; i++) {
        cno1 = find(belongs, elist.data[i].u);
        cno2 = find(belongs, elist.data[i].v);
        if (cno1 != cno2) {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n + 1;
            applyUnion(belongs, cno1, cno2);
        }
    }
}
int find(int belongs[], int vertexno) {
    return (belongs[vertexno]);
}
void applyUnion(int belongs[], int c1, int c2) {
    int i;
    for (i = 0; i < n; i++)
        if (belongs[i] == c2)
            belongs[i] = c1;
}
void sort() {
    int i, j;
    edge temp;
    for (i = 1; i < elist.n; i++)
        for (j = 0; j < elist.n - 1; j++)
            if (elist.data[j].w > elist.data[j + 1].w) {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
}
void print() {
    int i, cost = 0;
    printf("\nEdges in the Minimum Spanning Tree:\n");
    printf("Vertex 1\tVertex 2\tWeight\n");
    for (i = 0; i < spanlist.n; i++) {
        printf("%d\t\t%d\t\t%d\n", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        cost = cost + spanlist.data[i].w;
    }
    printf("\nTotal Minimum Spanning Tree Cost: %d\n", cost);
}
int main() {
    int i, j, total_cost;
    printf("====================================================\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the weighted adjacency matrix for the graph:\n");
    printf("Enter the edges and their weights (use 0 if no edge):\n");
    printf("Vertex 1\t\t\tVertex 2\tWeight\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &Graph[i][j]);
        }
    }
    kruskalAlgo();
    printf("\nMinimum Spanning Tree:");
    print();
 printf("====================================================\n");
    return 0;
}
