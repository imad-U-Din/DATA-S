#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int *array;
    unsigned capacity;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack)
{
    return (stack->top == stack->capacity - 1);
}

int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

void moveDisk(char sourceRod, char destinationRod, int disk)
{
    printf("Move the disk %d from '%c' to '%c'\n", disk, sourceRod, destinationRod);
}

void moveDisksBetweenTwoRods(struct Stack *from, struct Stack *to, char source, char destination)
{
    int rod1TopDisk = pop(from);
    int rod2TopDisk = pop(to);

    if (rod1TopDisk == -1)
    {
        push(from, rod2TopDisk);
        moveDisk(destination, source, rod2TopDisk);
    }
    else if (rod2TopDisk == -1)
    {
        push(to, rod1TopDisk);
        moveDisk(source, destination, rod1TopDisk);
    }
    else if (rod1TopDisk > rod2TopDisk)
    {
        push(from, rod1TopDisk);
        push(from, rod2TopDisk);
        moveDisk(destination, source, rod2TopDisk);
    }
    else
    {
        push(to, rod2TopDisk);
        push(to, rod1TopDisk);
        moveDisk(source, destination, rod1TopDisk);
    }
}

void toH(int no_of_disks, struct Stack *from, struct Stack *_using, struct Stack *to)
{
    int total_num_of_moves;
    char source = 'A', destination = 'C', auxiliary = 'B';

    if (no_of_disks % 2 == 0)
    {
        char temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }

    total_num_of_moves = pow(2, no_of_disks) - 1;

    for (int i = no_of_disks; i >= 1; i--)
        push(from, i);

    for (int i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1)
            moveDisksBetweenTwoRods(from, to, source, destination);
        else if (i % 3 == 2)
            moveDisksBetweenTwoRods(from, _using, source, auxiliary);
        else if (i % 3 == 0)
            moveDisksBetweenTwoRods(_using, to, auxiliary, destination);
    }
}

int main()
{
    unsigned no_of_disks;

    printf("Enter number of disks: ");
    scanf("%d", &no_of_disks);

    struct Stack *from = createStack(no_of_disks);
    struct Stack *_using = createStack(no_of_disks);
    struct Stack *to = createStack(no_of_disks);

    toH(no_of_disks, from, _using, to);

    free(from->array);
    free(_using->array);
    free(to->array);
    free(from);
    free(_using);
    free(to);

    return 0;
}
