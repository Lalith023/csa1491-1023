#include <stdio.h>
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
        if (is_comment(ptr)) {
            printf("Comment: %s", ptr);
            break;
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
    return strlen(constant) > 0;
}

int is_comment(char* line) {
    if (strncmp(line, "//", 2) == 0) {
        return 1;
    }
    if (strncmp(line, "/*", 2) == 0) {
        char *end_comment = strstr(line, "*/");
        if (end_comment != NULL) {
            return 1;
        }
    }
    return 0;
}
