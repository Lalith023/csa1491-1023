#include <stdio.h>

void countSpacesAndNewlines(char *expression) {
    int i = 0, spaces = 0, newlines = 0;
    while(expression[i] != '\0') {
        if(expression[i] == ' ') {
            spaces++;
        } else if(expression[i] == '\n') {
            newlines++;
        }
        i++;
    }
    printf("Number of spaces: %d\n", spaces);
    printf("Number of newlines: %d\n", newlines);
}
int main() {
    char expression[100];
    printf("Enter a string: ");
    fgets(expression, sizeof(expression), stdin); 
    countSpacesAndNewlines(expression);
    return 0;
}

