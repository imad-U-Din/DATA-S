#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char val) {
    if (!isFull(ptr)) {
        ptr->arr[++ptr->top] = val;
    }
}

char pop(struct stack *ptr) {
    if (!isEmpty(ptr)) {
        return ptr->arr[ptr->top--];
    }
    return -1;
}

char stackTop(struct stack *ptr) {
    return isEmpty(ptr) ? -1 : ptr->arr[ptr->top];
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') return 3;
    else if (ch == '+' || ch == '-') return 2;
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char *infixToPostfix(char *infix) {
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (char *)malloc(ptr->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            while (!isEmpty(ptr) && precedence(infix[i]) <= precedence(stackTop(ptr))) {
                postfix[j++] = pop(ptr);
            }
            push(ptr, infix[i++]);
        }
    }

    while (!isEmpty(ptr)) {
        postfix[j++] = pop(ptr);
    }
    postfix[j] = '\0';

    free(ptr->arr);
    free(ptr);
    return postfix;
}

char *infixToPrefix(char *infix) {
    reverseString(infix);
    
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    
    char *postfix = infixToPostfix(infix);
    reverseString(postfix);
    return postfix;
}

int main() {
    char infix[] = "p-q-r/a";
    printf("Prefix is %s\n", infixToPrefix(infix));
    return 0;
}
