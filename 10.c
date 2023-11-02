#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100


int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 1; v <= V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}


void printPath(int parent[], int v) {
    if (v == 0) {
        return;
    }
    printPath(parent, parent[v]);
    printf("%d->", v);
}


void printShortestPaths(int dist[], int parent[], int V, int source) {
    printf("Source Destination Cost Path\n");
    for (int v = 1; v <= V; v++) {
        if (v != source) {
            printf("%d %d %d %d->", source, v, dist[v], source);
            printPath(parent, v);
            printf("\b\b\n");
        }
    }
}


void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int source) {
    int dist[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];
    int parent[MAX_VERTICES];

    for (int v = 1; v <= V; v++) {
        dist[v] = INT_MAX;
        sptSet[v] = false;
    }

    dist[source] = 0;
    parent[source] = 0;

    for (int count = 1; count < V; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 1; v <= V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printShortestPaths(dist, parent, V, source);
}

int main() {
    int V;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &V);

    int source;
    printf("Enter the Source Vertex: ");
    scanf("%d", &source);

    int graph[MAX_VERTICES][MAX_VERTICES];

    FILE *file = fopen("inDiAdjMat1.dat", "r");
    if (file == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);

    dijkstra(graph, V, source);

    return 0;
}
