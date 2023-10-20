//Implementation of Breadth First Search in c 
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
};
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}
void BFS(int adjacency_matrix[][100], int vertices, int start_vertex) {
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    struct Queue* queue = createQueue();
    visited[start_vertex] = 1;
    printf("Breadth First Traversal starting from vertex %d: ", start_vertex);
    printf("%d ", start_vertex);
    enqueue(queue, start_vertex);
    while (!isEmpty(queue)) {
        int current_vertex = dequeue(queue);
        for (int i = 0; i < vertices; i++) {
            if (adjacency_matrix[current_vertex][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
}
int main() {
    int vertices, start_vertex;
    printf("----------------------------------------------------\n");
    printf("Name=, \nEn No.=");
    printf("\n-------------------------------------------------------\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int adjacency_matrix[100][100];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);
    BFS(adjacency_matrix, vertices, start_vertex);
    printf("----------------------------------------------------\n");
    return 0;
}
