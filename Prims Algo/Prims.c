#include <stdio.h>
#include <limits.h>

#define V 4  // Number of vertices

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the MST
void printMST(int parent[], int graph[V][V]) {
    printf("Edge  Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d   %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to find MST using Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Stores the MST
    int key[V];     // Minimum weights
    int mstSet[V];  // To track visited nodes

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;  
    parent[0] = -1;  

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

// Main function
int main() {
    int graph[V][V] = {
        {0, 2, 0, 6},
        {2, 0, 3, 8},
        {0, 3, 0, 5},
        {6, 8, 5, 0}
    };

    printf("Minimum Spanning Tree:\n");
    primMST(graph);

    return 0;
}
