#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int node;
  int distance;
} node_distance;

typedef struct {
  int num_nodes;
  node_distance **edges;
} graph;

void bfs(graph *g, int start_node, int *distances) {
  // Create a queue to store the nodes to be visited.
  int queue[g->num_nodes];
  int front = 0;
  int rear = 0;

  // Mark the start node as visited and initialize its distance to 0.
  distances[start_node] = 0;
  queue[rear++] = start_node;

  // While the queue is not empty, continue traversing the graph.
  while (front != rear) {
    // Get the next node to be visited from the queue.
    int node = queue[front++];

    // Iterate over all the neighbors of the current node.
    for (int i = 0; i < g->num_nodes; i++) {
      // If the current neighbor is not visited and there is an edge between
      // the current node and the neighbor, then add the neighbor to the queue
      // and update its distance.
      if (!distances[i] && g->edges[node][i].distance > 0) {
        distances[i] = distances[node] + 2;
        queue[rear++] = i;
      }
    }
  }
}

int main() {
  // Get the number of nodes in the graph.
  int num_nodes;
  printf("Enter the number of nodes in the graph: ");
  scanf("%d", &num_nodes);

  // Create a graph object.
  graph *g = (graph *)malloc(sizeof(graph));
  g->num_nodes = num_nodes;
  g->edges = (node_distance **)malloc(sizeof(node_distance *) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    g->edges[i] = (node_distance *)malloc(sizeof(node_distance) * num_nodes);
    for (int j = 0; j < num_nodes; j++) {
      g->edges[i][j].distance = -1;
    }
  }

  // Get the edges of the graph.
  int num_edges;
  printf("Enter the number of edges in the graph: ");
  scanf("%d", &num_edges);

  for (int i = 0; i < num_edges; i++) {
    int node1, node2;
    printf("Enter the two nodes connected by edge %d: ", i + 1);
    scanf("%d %d", &node1, &node2);

    g->edges[node1][node2].distance = 2;
    g->edges[node2][node1].distance = 2;
  }

  // Get the start node.
  int start_node;
  printf("Enter the start node: ");
  scanf("%d", &start_node);

  // Create an array to store the shortest distances to each of the other nodes from
  // the start node.
  int distances[num_nodes];
  for (int i = 0; i < num_nodes; i++) {
    distances[i] = -1;
  }

  // Perform breadth-first search and calculate the shortest distances.
  bfs(g, start_node, distances);

  // Display the breadth-first search traversal.
  printf("The breadth-first search traversal of the graph is: ");
  for (int i = 0; i < num_nodes; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  // Display the shortest distances to each of the other nodes from the start node.
  printf("The shortest distances to each of the other nodes from the start node are: ");
  for (int i = 0; i < num_nodes; i++) {
    printf("%d ", distances[i]);
  }
  printf("\n");

  // Free the allocated memory.
  for (int i = 0; i < num_nodes; i++) {
    free(g->edges[i]);
  }
  free(g->edges);
  free(g);

  return 0;
}
