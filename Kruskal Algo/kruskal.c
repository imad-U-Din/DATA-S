#include <stdio.h>
#include <stdlib.h>

#define V 5  // Number of vertices
#define E 7  // Number of edges

// Structure for an edge
struct Edge {
    int src, dest, weight;
};

// Structure for union-find
struct Subset {
    int parent;
};

// Find operation with path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union operation
void Union(struct Subset subsets[], int x, int y) {
    subsets[y].parent = x;  // Attach y's tree under x
}

// Compare function for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's MST Algorithm
void kruskalMST(struct Edge edges[], int vertices, int edgesCount) {
    qsort(edges, edgesCount, sizeof(struct Edge), compareEdges);  // Sort edges

    struct Subset subsets[vertices];  
    for (int v = 0; v < vertices; v++) 
        subsets[v].parent = v;  // Initialize each vertex as its own parent

    printf("Minimum Spanning Tree:\n");
    printf("Edge  Weight\n");

    int edgeCount = 0;
    for (int i = 0; edgeCount < vertices - 1 && i < edgesCount; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        if (x != y) {  // If it doesn't form a cycle
            printf("%d - %d   %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            Union(subsets, x, y);
            edgeCount++;
        }
    }
}

// Main function
int main() {
    struct Edge edges[E] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    kruskalMST(edges, V, E);
    return 0;
}
