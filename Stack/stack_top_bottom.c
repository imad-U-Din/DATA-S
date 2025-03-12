#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, int value) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %d to the stack\n", value);
    } else {
        ptr->arr[++(ptr->top)] = value;
    }
}

int pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1; // Use only when -1 is guaranteed not to be a valid stack value
    } else {
        return ptr->arr[(ptr->top)--];
    }
}

int peek(struct stack *sp, int position) {
    int arrayIndex = sp->top - position + 1;
    if (arrayIndex < 0 || arrayIndex > sp->top) {
        printf("Invalid position for the stack\n");
        return -1;
    }
    return sp->arr[arrayIndex];
}

int stackTop(struct stack *sp){
    return sp->arr[sp->top];
}

int stackBottom (struct stack * sp){
    return sp->arr[0];
}

int main() {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));

    push(sp, 20);
    push(sp, 3);
    push(sp, 2);
    push(sp, 4);
    push(sp, 9);
    push(sp, 8);
    push(sp, 4);
    push(sp, 5);

    // printf("After pushing, Full: %d\n", isFull(sp));
    // printf("After pushing, Empty: %d\n", isEmpty(sp));

    // printf("Popped %d from the stack\n", pop(sp));
    // // LAST IN FIRST OUT (LIFO)


    // for (int j = 1; j <= sp->top + 1; j++) {
    //     printf("The value at position %d is %d\n", j, peek(sp, j));
    // }

    // free(sp->arr);
    // free(sp);

    printf("The top most value of this stcak is %d\n",stackTop(sp));
    printf("The bottom most value of this stcak is %d\n",stackBottom(sp));

    return 0;
}
