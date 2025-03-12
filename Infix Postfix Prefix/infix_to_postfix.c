#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *ptr) {
    if (ptr->top == -1) return -1; // Return a default value if stack is empty
    return ptr->arr[ptr->top];
}

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow, cannot push %c to the stack\n", val);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow, cannot pop from the stack\n");
        return -1;
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') return 3;
    else if (ch == '+' || ch == '-') return 2;
    else return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

char *infixToPostfix(char *infix) {
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (char *)malloc(ptr->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0; // `i` tracks infix, `j` tracks postfix

    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) { // If operand, add to postfix
            postfix[j++] = infix[i++];
        } else {
            while (!isEmpty(ptr) && precedence(infix[i]) <= precedence(stackTop(ptr))) {
                postfix[j++] = pop(ptr);
            }
            push(ptr, infix[i++]);
        }
    }

    while (!isEmpty(ptr)) { // Pop remaining operators
        postfix[j++] = pop(ptr);
    }

    postfix[j] = '\0';
    free(ptr->arr);
    free(ptr);
    
    return postfix;
}

int main() {
    char *infix = "p-q-r/a";
    printf("Postfix is %s\n", infixToPostfix(infix));

    return 0;
}
