#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int evaluate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int evaluatePostfix(char *exp) {
    int length = strlen(exp);
    int stack[100], top = -1;
    
    for (int i = 0; i < length; i++) {
        if (isdigit(exp[i])) {
            stack[++top] = exp[i] - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = evaluate(a, b, exp[i]);
        }
    }
    return stack[top];
}

int main() {
    char exp[] = "923*+84/-"; // Example postfix expression
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}
