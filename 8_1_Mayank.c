#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the graph
typedef struct node {
  int value;
  int distance;
  struct node *next;
} node;

// Define a queue to store nodes to be visited
typedef struct queue {
  node *front;
  node *rear;
} queue;

// Initialize the queue
void init_queue(queue *q) {
  q->front = NULL;
  q->rear = NULL;
}

// Enqueue a node to the queue
void enqueue(queue *q, node *n) {
  if (q->rear == NULL) {
    q->front = n;
    q->rear = n;
  } else {
    q->rear->next = n;
    q->rear = n;
  }
}

// Dequeue a node from the queue
node *dequeue(queue *q) {
  if (q->front == NULL) {
    return NULL;
  } else {
    node *n = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
      q->rear = NULL;
    }
    return n;
  }
}

// Check if the queue is empty
int is_queue_empty(queue *q) {
  return q->front == NULL;
}

// Perform a breadth-first search on the graph starting from the given node
void bfs(node *graph, int start_node) {
  // Create a queue to store nodes to be visited
  queue q;
  init_queue(&q);

  // Enqueue the start node
  node *n = graph + start_node;
  n->distance = 0;
  enqueue(&q, n);

  // While the queue is not empty
  while (!is_queue_empty(&q)) {
    // Dequeue a node from the queue
    n = dequeue(&q);

    // Visit the node
    printf("%d ", n->value);

    // Enqueue all adjacent nodes that have not been visited
    for (int i = 0; i < n->degree; i++) {
      node *adj = graph + n->neighbors[i];
      if (adj->distance == -1) {
        adj->distance = n->distance + 1;
        enqueue(&q, adj);
      }
    }
  }
}

// Print the shortest distance to each node from the start node
void print_distances(node *graph, int start_node) {
  for (int i = 0; i < graph->size; i++) {
    if (graph[i].distance != -1) {
      printf("%d ", graph[i].distance);
    } else {
      printf("-1 ");
    }
  }
}

int main() {
  // Get the number of nodes and edges in the graph
  int n, m;
  scanf("%d %d", &n, &m);

  // Create a graph to store the nodes and edges
  node *graph = malloc(sizeof(node) * n);
  for (int i = 0; i < n; i++) {
    graph[i].value = i;
    graph[i].distance = -1;
    graph[i].degree = 0;
  }

  // Read the edges from the input
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u].neighbors[graph[u].degree++] = v;
    graph[v].neighbors[graph[v].degree++] = u;
  }

  // Get the start node
  int s;
  scanf("%d", &s);

  // Perform a breadth-first search on the graph
  bfs(graph, s);

  // Print the shortest distance to each node from the start node
  printf("\nDistance: ");
  print_distances(graph, s);

  // Free the allocated memory
  free(graph);

  return 0;
}
