Certainly! Here's an implementation of Depth-First Search (DFS) for graph traversal in C:

```c
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int vertices;
    struct Node** adjacency_list;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* create_graph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacency_list = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; ++i) {
        graph->adjacency_list[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void add_edge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = create_node(dest);
    newNode->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = newNode;
}

// Function to perform DFS from a given vertex
void dfs_recursive(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* current = graph->adjacency_list[vertex];
    while (current != NULL) {
        if (!visited[current->data]) {
            dfs_recursive(graph, current->data, visited);
        }
        current = current->next;
    }
}

// Function to initialize DFS and handle connected components
void dfs(struct Graph* graph, int start_vertex) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = 0;
    }

    dfs_recursive(graph, start_vertex, visited);
    free(visited);
}

// Example Usage:
int main() {
    struct Graph* graph = create_graph(4);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 3);

    printf("DFS starting from vertex 2:\n");
    dfs(graph, 2);

    return 0;
}
```

This C code defines a simple graph structure and functions to perform DFS traversal. The `dfs_recursive` function is a recursive helper function for DFS, and the `dfs` function initializes the visited array and calls the recursive function for the specified starting vertex.
