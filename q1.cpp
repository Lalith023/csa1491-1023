#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_IDENTIFIER_LENGTH 50
#define MAX_CONSTANT_LENGTH 20
int is_operator(char);
int is_valid_identifier(char*);
int is_valid_constant(char*);
int main() {
    char input[1000];
    printf("Enter the code: ");
    fgets(input, sizeof(input), stdin);
    char *ptr = input;
    while (*ptr != '\0') {
        if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n') {
            ptr++;
            continue;
        }
        if (*ptr == '/' && *(ptr + 1) == '/') {
            while (*ptr != '\n') {
                ptr++;
            }
            continue;
        }
        if (is_operator(*ptr)) {
            printf("Operator: %c\n", *ptr);
            ptr++;
            continue;
        }
        if (isalpha(*ptr) || *ptr == '_') {
            char identifier[MAX_IDENTIFIER_LENGTH + 1];
            int i = 0;
            while (isalnum(*ptr) || *ptr == '_') {
                if (i < MAX_IDENTIFIER_LENGTH) {
                    identifier[i++] = *ptr;
                }
                ptr++;
            }
            identifier[i] = '\0';
            if (is_valid_identifier(identifier)) {
                printf("Identifier: %s\n", identifier);
            } else {
                printf("Invalid identifier: %s\n", identifier);
            }
            continue;
        }
        if (isdigit(*ptr)) {
            char constant[MAX_CONSTANT_LENGTH + 1];
            int i = 0;
            while (isdigit(*ptr) || *ptr == '.') {
                if (i < MAX_CONSTANT_LENGTH) {
                    constant[i++] = *ptr;
                }
                ptr++;
            }
            constant[i] = '\0';
            if (is_valid_constant(constant)) {
                printf("Constant: %s\n", constant);
            } else {
                printf("Invalid constant: %s\n", constant);
            }
            continue;
        }
        ptr++;
    }
    return 0;
}
int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>');
}
int is_valid_identifier(char* identifier) {
    return strlen(identifier) > 0;
}
int is_valid_constant(char* constant) {
    return strlen(constant);
}
