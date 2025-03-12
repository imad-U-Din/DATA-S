#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, minIndex;
    
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the shortest distances from the source
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Stores shortest distances from src to each vertex
    int visited[V];   // Tracks visited vertices

    // Initialize distances with infinity (INT_MAX) and visited array as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;  // Distance to source is always 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);  // Get the nearest unvisited vertex
        visited[u] = 1;  // Mark it as visited

        // Update the distance of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

// Main function
int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int source = 0;  // Start from vertex 0
    printf("Dijkstra's Algorithm from Source %d:\n", source);
    dijkstra(graph, source);

    return 0;
}
