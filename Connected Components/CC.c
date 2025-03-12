#include <stdio.h>

#define V 7  // Number of vertices

int adjMatrix[V][V] = { // Adjacency matrix representation of the graph
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
};

int visited[V] = {0};  // Keeps track of visited nodes

// DFS Function
void DFS(int node) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adjMatrix[node][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// Function to find all connected components
void findConnectedComponents() {
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) { // If node is not visited, it's a new component
            printf("Component %d: ", ++count);
            DFS(i);
            printf("\n");
        }
    }
}

// Main function
int main() {
    printf("Connected Components in the Graph:\n");
    findConnectedComponents();
    return 0;
}
