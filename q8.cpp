#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 10

void findFirst(char, int, int);
void findFollow(char);
void addToResultSet(char);

int numOfProductions;
char productionSet[MAX][MAX];
char firstSet[MAX];
char followSet[MAX];
int firstSetCount;
int followSetCount;

int main() {
    int i;
    char choice;
    printf("Enter the number of productions: ");
    scanf("%d", &numOfProductions);
    printf("Enter the productions (e.g., S->AaAb):\n");
    for (i = 0; i < numOfProductions; i++) {
        scanf("%s", productionSet[i]);
    }

    char symbol;
    printf("Enter the symbol to find FOLLOW set: ");
    scanf(" %c", &symbol);

    followSetCount = 0;
    findFollow(symbol);

    printf("FOLLOW(%c) = { ", symbol);
    for (i = 0; i < followSetCount; i++) {
        printf("%c ", followSet[i]);
    }
    printf("}\n");

    return 0;
}

void findFirst(char symbol, int productionIndex, int symbolIndex) {
    int i, j;
    char subSymbol;

    if (!(isupper(symbol))) {
        addToResultSet(symbol);
        return;
    }

    for (i = 0; i < numOfProductions; i++) {
        if (productionSet[i][0] == symbol) {
            if (productionSet[i][2] == '?') {
                addToResultSet('?');
            } else {
                j = 2;
                while (productionSet[i][j] != '\0') {
                    subSymbol = productionSet[i][j];
                    findFirst(subSymbol, i, j);
                    j++;
                }
            }
        }
    }
}

void findFollow(char symbol) {
    int i, j;
    char subSymbol;

    if (symbol == productionSet[0][0]) {
        addToResultSet('$'); // Add end of input marker
    }

    for (i = 0; i < numOfProductions; i++) {
        for (j = 2; j < strlen(productionSet[i]); j++) {
            if (productionSet[i][j] == symbol) {
                if (productionSet[i][j + 1] != '\0') {
                    findFirst(productionSet[i][j + 1], i, (j + 2));
                }

                if (productionSet[i][j + 1] == '\0' && symbol != productionSet[i][0]) {
                    findFollow(productionSet[i][0]);
                }
            }
        }
    }
}

void addToResultSet(char symbol) {
    int i;
    for (i = 0; i < followSetCount; i++) {
        if (followSet[i] == symbol) {
            return;
        }
    }
    followSet[followSetCount++] = symbol;
}

