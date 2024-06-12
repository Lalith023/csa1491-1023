#include <stdio.h>

void recognizeOperators(char *expression) {
    int i = 0;
    while(expression[i] != '\0') {
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            printf("Operator found: %c\n", expression[i]);
        }
        i++;
    }
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);  // read string
    recognizeOperators(expression);
    return 0;
}

