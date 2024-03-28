#include <stdio.h>

int main() {
    char input_text[] = "Hello, world!\nThis is a sample text with spaces.";
    int whitespace_count = 0;
    int newline_count = 0;

    for (int i = 0; input_text[i] != '\0'; i++) {
        if (input_text[i] == ' ' || input_text[i] == '\t') {
            whitespace_count++;
        }
        if (input_text[i] == '\n') {
            newline_count++;
        }
    }

    printf("Number of spaces: %d\n", whitespace_count);
    printf("Number of newlines: %d\n", newline_count);

    return 0;
}

