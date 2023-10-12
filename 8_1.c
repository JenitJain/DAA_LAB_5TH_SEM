#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int id;
    struct Node *neighbors[MAX_NODES];
    int distance;
} Node;

typedef struct {
    Node *nodes[MAX_NODES];
    int num_nodes;
} Graph;

void add_node(Graph *graph, Node *node) {
    graph->nodes[node->id] = node;
    graph->num_nodes++;
}

void add_edge(Graph *graph, Node *node1, Node *node2) {
    node1->neighbors[node2->id] = node2;
    node2->neighbors[node1->id] = node1;
}

void bfs_traversal(Graph *graph, Node *start_node) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    queue[rear++] = start_node->id;

    while (front != rear) {
        int current_node_id = queue[front++];

        Node *current_node = graph->nodes[current_node_id];

        for (int i = 0; i < graph->num_nodes; i++) {
            Node *neighbor = current_node->neighbors[i];

            if (neighbor != NULL) {
                if (neighbor->distance == -1) {
                    neighbor->distance = current_node->distance + 1;
                    queue[rear++] = neighbor->id;
                }
            }
        }
    }
}

void bfs_shortest_distance(Graph *graph, Node *start_node) {
    bfs_traversal(graph, start_node);

    int distances[MAX_NODES];
    for (int i = 0; i < graph->num_nodes; i++) {
        distances[i] = graph->nodes[i]->distance;
    }

    return distances;
}

int main() {
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);

    Graph *graph = malloc(sizeof(Graph));
    graph->num_nodes = 0;

    for (int i = 0; i < num_nodes; i++) {
        Node *node = malloc(sizeof(Node));
        node->id = i;
        node->distance = -1;

        add_node(graph, node);
    }

    for (int i = 0; i < num_edges; i++) {
        int node1_id, node2_id;
        scanf("%d %d", &node1_id, &node2_id);

        Node *node1 = graph->nodes[node1_id];
        Node *node2 = graph->nodes[node2_id];

        add_edge(graph, node1, node2);
    }

    int start_node_id;
    scanf("%d", &start_node_id);

    Node *start_node = graph->nodes[start_node_id];

    int *distances = bfs_shortest_distance(graph, start_node);

    printf("BFS Traversal: ");
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Distance: ");
    for (int i = 0; i < graph->num_nodes; i++) {
        if (distances[i] == -1) {
            printf("Unreachable ");
        } else {
            printf("%d ", distances[i]);
        }
    }
    printf("\n");

    free(graph);
    free(distances);

    return 0;
}
