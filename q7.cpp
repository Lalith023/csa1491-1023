#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<ctype.h>
#define MAX 10

void findFirst(char, int, int);
void addToResultSet(char);

int numOfProductions;
char productionSet[MAX][MAX];
char firstSet[MAX];
int firstSetCount;

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
    printf("Enter the symbol to find FIRST set: ");
    scanf(" %c", &symbol);

    firstSetCount = 0;
    findFirst(symbol, 0, 0);

    printf("FIRST(%c) = { ", symbol);
    for (i = 0; i < firstSetCount; i++) {
        printf("%c ", firstSet[i]);
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

void addToResultSet(char symbol) {
    int i;
    for (i = 0; i < firstSetCount; i++) {
        if (firstSet[i] == symbol) {
            return;
        }
    }
    firstSet[firstSetCount++] = symbol;
}

