#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int capacity;
    int *array;
} Stack;

Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(capacity * sizeof(int));
    return stack;
}

void push(Stack *stack, int item)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

typedef struct Queue
{
    Stack *stack1;
    Stack *stack2;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

void enqueue(Queue *queue, int item)
{
    push(queue->stack1, item);
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue->stack2))
    {
        while (!isEmpty(queue->stack1))
        {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}

int main()
{
    Queue *queue = createQueue(10);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    enqueue(queue, 40);
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    return 0;
}
