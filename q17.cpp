#include <stdio.h>
#include <stdlib.h>

// Define the grammar
char grammar[3][10] = {"E=E+T|T", "T=T*F|F", "F=(E)|id"};

// Function to check if a character is non-terminal
int isNonTerminal(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to compute LEADING set
void computeLeading(char c) {
    for (int i = 0; i < 3; i++) {
        if (grammar[i][0] == c) {
            if (!isNonTerminal(grammar[i][2])) {
                printf("%c ", grammar[i][2]);
            } else {
                computeLeading(grammar[i][2]);
            }
        }
    }
}

int main() {
    char nonTerminal;
    printf("Enter the non-terminal: ");
    scanf("%c", &nonTerminal);

    printf("LEADING(%c) = { ", nonTerminal);
    computeLeading(nonTerminal);
    printf("}\n");

    return 0;
}

