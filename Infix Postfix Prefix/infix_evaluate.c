#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int evaluate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int evaluateInfix(char *exp) {
    int a = 0, b = 0;
    char op = '\0';
    
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            if (a == 0) a = exp[i] - '0';
            else b = exp[i] - '0';
        } else {
            op = exp[i];
        }
    }
    return evaluate(a, b, op);
}

int main() {
    char exp[] = "3+5";
    printf("Result: %d\n", evaluateInfix(exp));
    return 0;
}
