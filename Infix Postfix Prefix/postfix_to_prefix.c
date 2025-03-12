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

char *postfixToPrefix(char *postfix) {
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (char **)malloc(ptr->size * sizeof(char *));

    for (int i = 0; i < strlen(postfix); i++) {
        if (postfix[i] >= 'a' && postfix[i] <= 'z') {
            char *operand = (char *)malloc(2 * sizeof(char));
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(ptr, operand);
        } else {
            char *op1 = pop(ptr);
            char *op2 = pop(ptr);
            char *expr = (char *)malloc(strlen(op1) + strlen(op2) + 2);
            sprintf(expr, "%c%s%s", postfix[i], op2, op1);
            push(ptr, expr);
        }
    }
    char *prefix = pop(ptr);
    free(ptr->arr);
    free(ptr);
    return prefix;
}

int main() {
    char postfix[] = "pq-r/a-";
    printf("Prefix is %s\n", postfixToPrefix(postfix));
    return 0;
}
