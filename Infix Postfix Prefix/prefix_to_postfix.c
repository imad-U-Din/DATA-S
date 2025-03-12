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

char *prefixToPostfix(char *prefix) {
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (char **)malloc(ptr->size * sizeof(char *));
    int length = strlen(prefix);
    
    for (int i = length - 1; i >= 0; i--) {
        if (prefix[i] >= 'a' && prefix[i] <= 'z') {
            char *operand = (char *)malloc(2 * sizeof(char));
            operand[0] = prefix[i];
            operand[1] = '\0';
            push(ptr, operand);
        } else {
            char *op1 = pop(ptr);
            char *op2 = pop(ptr);
            char *expr = (char *)malloc(strlen(op1) + strlen(op2) + 2);
            sprintf(expr, "%s%s%c", op1, op2, prefix[i]);
            push(ptr, expr);
        }
    }
    char *postfix = pop(ptr);
    free(ptr->arr);
    free(ptr);
    return postfix;
}

int main() {
    char prefix[] = "-p/qra";
    printf("Postfix is %s\n", prefixToPostfix(prefix));
    return 0;
}
