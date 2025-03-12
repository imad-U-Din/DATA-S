#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue *q) {
    return q->r == q->f;
}

int isFull(struct queue *q) {
    return q->r == q->size - 1;
}

void enqueue(struct queue *q, int val) {
    if (isFull(q)) {
        printf("This Queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("This Queue is empty\n");
    } else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main() {
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));

    // BFS Implementation
    int node;  // Remove redeclaration issue
    int i = 0; // Start BFS from node 0 (not 1)
    int visited[7] = {0}; // Initialize all as unvisited
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);

    while (!isEmpty(&q)) {
        node = dequeue(&q); // Use existing node variable
        for (int j = 0; j < 7; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    free(q.arr); // Free allocated memory
    return 0;
}
