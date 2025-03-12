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

int evaluatePrefix(char *exp) {
    int length = strlen(exp);
    int stack[100], top = -1;
    
    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            stack[++top] = exp[i] - '0';
        } else {
            int a = stack[top--];
            int b = stack[top--];
            stack[++top] = evaluate(a, b, exp[i]);
        }
    }
    return stack[top];
}

int main() {
    char exp[] = "-+9*23/84"; // Example prefix expression
    printf("Result: %d\n", evaluatePrefix(exp));
    return 0;
}
