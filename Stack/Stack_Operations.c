#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! cannot push %d to the stack\n",value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack*ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow! cannot pop from the stack\n");
        return -1;  //IF -1 IS PRESENT IN THE STACK THEN USE ANOTHER VALUE    
        }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 8;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created\n");

    printf("Before pushing, Full:%d\n", isFull(sp));
    printf("Before pushing, Empty:%d\n", isEmpty(sp));

    push(sp, 20);
    push(sp, 3);
    push(sp, 2);
    push(sp, 4);
    push(sp, 9);
    push(sp, 8);
    push(sp, 4);
    push(sp, 5);
    //push(sp, 6);

    printf("After pushing, Full:%d\n", isFull(sp));
    printf("After pushing, Empty:%d\n", isEmpty(sp));

    printf("Popped %d from the stack\n",pop(sp));
    //LAST IN FIRST OUT ( LIFO )
    return 0;
}