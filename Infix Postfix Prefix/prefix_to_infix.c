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

char *prefixToInfix(char *prefix) {
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (char **)malloc(ptr->size * sizeof(char *));
    int length = strlen(prefix);
    
    for (int i = length - 1; i >= 0; i--) {
        if ((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z') || (prefix[i] >= '0' && prefix[i] <= '9')) {
            char *operand = (char *)malloc(2 * sizeof(char));
            operand[0] = prefix[i];
            operand[1] = '\0';
            push(ptr, operand);
        } else {
            char *op1 = pop(ptr);
            char *op2 = pop(ptr);
            char *expr = (char *)malloc(strlen(op1) + strlen(op2) + 4);
            sprintf(expr, "(%s%c%s)", op1, prefix[i], op2);
            push(ptr, expr);
        }
    }
    char *infix = pop(ptr);
    free(ptr->arr);
    free(ptr);
    return infix;
}

int main() {
    char prefix[] = "-p/qra";
    printf("Infix is %s\n", prefixToInfix(prefix));
    return 0;
}
