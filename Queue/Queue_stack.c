#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int *arr;
};

// Function to create a stack
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*)malloc(size * sizeof(int));
    return stack;
}

// Enqueue operation (Push)
void enqueue(struct Stack *stack, int val) {
    stack->arr[++stack->top] = val;
}

// Pop operation
int pop(struct Stack *stack) {
    if (stack->top == -1) return -1; // Stack underflow
    return stack->arr[stack->top--];
}

// Recursive function to dequeue (FIFO behavior)
int dequeue(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    int x = pop(stack); // Pop the top element

    if (stack->top == -1) {
        // If stack is empty after popping, this was the first inserted element
        return x;
    }

    int result = dequeue(stack); // Recursively remove next element

    enqueue(stack, x); // Push back all popped elements

    return result;
}

// Function to print queue elements (FIFO order)
void printQueue(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]); // Print from bottom to top
    }
    printf("\n");
}

int main() {
    struct Stack *queue = createStack(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    
    printQueue(queue); // Output: Queue: 1 2 3

    printf("Dequeued: %d\n", dequeue(queue)); // Output: 1
    printQueue(queue); // Output: Queue: 2 3

    printf("Dequeued: %d\n", dequeue(queue)); // Output: 2
    printQueue(queue); // Output: Queue: 3

    return 0;
}
