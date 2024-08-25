#include <stdio.h>
#include <limits.h>

#define MAX 100  // Define a maximum number of vertices
#define INF INT_MAX  // Define INF as INT_MAX

// Function to print the solution matrix
void printSolution(int dist[MAX][MAX], int V) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[MAX][MAX], int V) {
    int dist[MAX][MAX];  // dist[i][j] will hold the shortest distance from i to j

    // Initialize the solution matrix same as input graph matrix.
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Add all vertices one by one to the set of intermediate vertices.
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist, V);
}

int main() {
    int V;
    printf("Enter the number of vertices (maximum %d): ", MAX);
    scanf("%d", &V);

    if (V > MAX) {
        printf("Error: The number of vertices exceeds the maximum allowed (%d).\n", MAX);
        return 1;
    }

    int graph[MAX][MAX];

    printf("Enter the adjacency matrix (type 'INF' for infinity):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            char input[10];
            scanf("%s", input);

            if (strcmp(input, "INF") == 0) {
                graph[i][j] = INF;
            } else {
                graph[i][j] = atoi(input);
            }
        }
    }

    // Run Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}
