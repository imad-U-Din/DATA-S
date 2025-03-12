#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *arr;
};

// Check if the queue is full
int isFull(struct queue *q) {
    return q->rear == q->size - 1;
}

// Check if the queue is empty
int isEmpty(struct queue *q) {
    return q->rear == q->front;
}

// Enqueue operation
void enqueue(struct queue *q, int val) {
    if (isFull(q)) {
        printf("This Queue is full\n");
    } else {
        q->rear++;
        q->arr[q->rear] = val;
    }
}

// Dequeue operation
int dequeue(struct queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("This Queue is empty\n");
    } else {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

// Function to print the queue
void printQueue(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct queue q;
    q.size = 50;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    
    printQueue(&q); // Output: Queue: 12 15 1

    printf("Dequeuing element %d\n", dequeue(&q)); // Output: 12
    printQueue(&q); // Output: Queue: 15 1

    printf("Dequeuing element %d\n", dequeue(&q)); // Output: 15
    printQueue(&q); // Output: Queue: 1

    if (isEmpty(&q)) {
        printf("Queue is empty\n");
    }

    if (isFull(&q)) {
        printf("Queue is full\n");
    }

    free(q.arr); // Free allocated memory
    return 0;
}
