#include <stdio.h>

int calculate(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero\n");
                return -1; // Indicate error
            }
            return a / b;
        default:
            printf("Error: Invalid operator\n");
            return -1; // Indicate error
    }
}

int main() {
    char expr[50];
    int a, b, result,op;

    printf("Enter a simple expression (e.g., 2 + 3 * 4): ");
    fgets(expr, sizeof(expr), stdin);

    // Extract operands and operator (assumes valid format)
    sscanf(expr, "%d %c %d", &a, &op, &b);

    result = calculate(a, b, op);

    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}
