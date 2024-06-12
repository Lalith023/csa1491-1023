#include <stdio.h>
#include <ctype.h>
#include<string.h>

int isValidIdentifier(char *identifier) {
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
int main() {
    char identifier[100];
    printf("Enter an identifier: ");
    fgets(identifier, sizeof(identifier), stdin);  
    identifier[strcspn(identifier, "\n")] = 0;  
    if (isValidIdentifier(identifier)) {
        printf("The identifier is valid.\n");
    } else {
        printf("The identifier is not valid.\n");
    }
    return 0;
}

