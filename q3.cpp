#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 50
#define MAX_CONSTANT_LENGTH 20

int is_operator(char);
int is_valid_identifier(char*);
int is_valid_constant(char*);
int is_comment(char*);

int main() {
    char input[1000];
    printf("Enter the code: ");
    fgets(input, sizeof(input), stdin);

    char *ptr = input;

    while (*ptr != '\0') {
        // Ignore spaces, tabs, and new lines
        if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n') {
            ptr++;
            continue;
        }

        // Check if it's a comment
        if (is_comment(ptr)) {
            // Skip single-line comment
            if (strncmp(ptr, "//", 2) == 0) {
                while (*ptr != '\n' && *ptr != '\0') {
                    ptr++;
                }
            }
            // Skip multi-line comment
            else if (strncmp(ptr, "/*", 2) == 0) {
                ptr += 2;
                while (strncmp(ptr, "*/", 2) != 0 && *ptr != '\0') {
                    ptr++;
                }
                if (*ptr != '\0') {
                    ptr += 2;
                }
            }
            continue;
        }

        // Check if it's an operator
        if (is_operator(*ptr)) {
            printf("Operator: %c\n", *ptr);
            ptr++;
            continue;
        }

        // Check if it's an identifier
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

        // Check if it's a constant
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
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return 0;
    }
    for (int i = 1; identifier[i] != '\0'; i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int is_valid_constant(char* constant) {
    int dot_count = 0;
    for (int i = 0; constant[i] != '\0'; i++) {
        if (!isdigit(constant[i])) {
            if (constant[i] == '.' && dot_count == 0) {
                dot_count++;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

int is_comment(char* line) {
    // Check for single-line comment
    if (strncmp(line, "//", 2) == 0) {
        return 1;
    }
    // Check for multi-line comment
    if (strncmp(line, "/*", 2) == 0) {
        char *end_comment = strstr(line, "*/");
        if (end_comment != NULL) {
            return 1;
        }
    }
    return 0;
}

