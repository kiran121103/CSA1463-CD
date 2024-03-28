#include <stdio.h>

int main() {
    int a, b, c, result1, result2;

    // Input values
    printf("Enter values for a, b, and c: ");
    scanf("%d %d %d", &a, &b, &c);

    // Common subexpression: a * b
    result1 = a * b;
    result2 = result1 + c;
    printf("Result 1: %d\n", result2);

    // Eliminating common subexpression
    result2 = (a * b) + c;
    printf("Result 2: %d\n", result2);

    return 0;
}

