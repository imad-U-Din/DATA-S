#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char **arr;
};

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

void push(struct stack *ptr, char *val) {
    ptr->arr[++ptr->top] = val;
}

char *pop(struct stack *ptr) {
    return isEmpty(ptr) ? "" : ptr->arr[ptr->top--];
}

char *postfixToInfix(char *postfix) {
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (char **)malloc(ptr->size * sizeof(char *));
    int length = strlen(postfix);
    
    for (int i = 0; i < length; i++) {
        if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z') || (postfix[i] >= '0' && postfix[i] <= '9')) {
            char *operand = (char *)malloc(2 * sizeof(char));
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(ptr, operand);
        } else {
            char *op2 = pop(ptr);
            char *op1 = pop(ptr);
            char *expr = (char *)malloc(strlen(op1) + strlen(op2) + 4);
            sprintf(expr, "(%s%c%s)", op1, postfix[i], op2);
            push(ptr, expr);
        }
    }
    char *infix = pop(ptr);
    free(ptr->arr);
    free(ptr);
    return infix;
}

int main() {
    char postfix[] = "pq-ra/";
    printf("Infix is %s\n", postfixToInfix(postfix));
    return 0;
}
