#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF -1

int graph[MAX_NODES][MAX_NODES];
int queue[MAX_NODES];
int visited[MAX_NODES];
int distance[MAX_NODES];

int front = -1, rear = -1;

void enqueue(int node) {
    if (rear == MAX_NODES - 1) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = node;
    }
}

int dequeue() {
    int node;
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        node = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return node;
    }
}

int isQueueEmpty() {
    return front == -1;
}

void BFS(int n, int start) {
    int i, current;
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        distance[i] = INF;
    }

    enqueue(start);
    visited[start] = 1;
    distance[start] = 0;

    printf("BFS Traversal: %d ", start);

    while (!isQueueEmpty()) {
        current = dequeue();
        for (i = 1; i <= n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
                distance[i] = distance[current] + 2;
                printf("%d ", i);
            }
        }
    }
}

int main() {
    int n, m, u, v, s;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Describe edges between nodes 'u' and 'v': ");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    printf("Start node number: ");
    scanf("%d", &s);

    BFS(n, s);

    printf("\nDistance [");
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            printf(" ");
        }
        printf("%d", distance[i]);
    }
    printf("]\n");

    return 0;
}
