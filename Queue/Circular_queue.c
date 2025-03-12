#include <stdio.h>
#include <stdlib.h>

struct circularQueue {
    int size;
    int front;
    int rear;
    int *arr;
};

// Check if the queue is empty
int isEmpty(struct circularQueue *q) {
    return q->rear == q->front;
}

// Check if the queue is full
int isFull(struct circularQueue *q) {
    return (q->rear + 1) % q->size == q->front;
}

// Enqueue operation
void enqueue(struct circularQueue *q, int val) {
    if (isFull(q)) {
        printf("The Queue is full\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
        printf("Enqueued Element: %d\n", val);
    }
}

// Dequeue operation
int dequeue(struct circularQueue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("This Queue is empty\n");
    } else {
        q->front = (q->front + 1) % q->size;
        a = q->arr[q->front];
    }
    return a;
}

// Function to print queue elements in correct order
void printQueue(struct circularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i = (q->front + 1) % q->size;
    while (i != (q->rear + 1) % q->size) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() {
    struct circularQueue q;
    q.size = 4; // We can only store 3 elements due to circular queue condition
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);

    printQueue(&q); // Output: Queue: 12 15 1

    printf("Dequeuing element %d\n", dequeue(&q)); // Output: 12
    printf("Dequeuing element %d\n", dequeue(&q)); // Output: 15

    printQueue(&q); // Output: Queue: 1

    enqueue(&q, 45);
    printQueue(&q); // Output: Queue: 1 45

    if (isEmpty(&q)) {
        printf("Queue is empty\n");
    }

    if (isFull(&q)) {
        printf("Queue is full\n");
    }

    free(q.arr); // Free allocated memory
    return 0;
}
