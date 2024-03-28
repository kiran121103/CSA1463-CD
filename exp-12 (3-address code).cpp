#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temp_count = 0;
struct ThreeAddressCode {
    char result[10];
    char op;
    char arg1[10];
    char arg2[10];
};

char* newTemp() {
    char* temp = (char*)malloc(10 * sizeof(char));
    sprintf(temp, "t%d", temp_count++);
    return temp;
}

// Function to generate three-address code for a given expression
void generateThreeAddressCode(char* expression) {
    struct ThreeAddressCode code;
    char* temp = newTemp();
    int i = 0;

    while (expression[i] != '\0') {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            code.result[0] = '\0';
            code.op = expression[i];
            strncpy(code.arg1, temp, sizeof(code.arg1));
            code.arg1[sizeof(code.arg1) - 1] = '\0';
            strncpy(code.arg2, &expression[i + 1], sizeof(code.arg2));
            code.arg2[sizeof(code.arg2) - 1] = '\0';

            printf("%s = %s %c %s\n", temp, code.arg1, code.op, code.arg2);

            strncpy(code.result, temp, sizeof(code.result));
            code.result[sizeof(code.result) - 1] = '\0';
            temp = newTemp();
        }
        i++;
    }

    printf("%s = %s\n", temp, expression);
}

int main() {
    char expression[100];

    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0'; // Remove trailing newline

    generateThreeAddressCode(expression);

    return 0;
}

