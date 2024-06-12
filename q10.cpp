#include <stdio.h>
#include <string.h>
#define MAX 10
void eliminateLeftFactoring(char productions[MAX][MAX], int numOfProductions);
int main() {
    int numOfProductions, i;
    char productions[MAX][MAX];
    printf("Enter the number of productions: ");
    scanf("%d", &numOfProductions);
    printf("Enter the productions (e.g., S->iEtS/iEtSeS/a):\n");
    for (i = 0; i < numOfProductions; i++) {
        scanf("%s", productions[i]);
    }
    eliminateLeftFactoring(productions, numOfProductions);
    return 0;
}
void eliminateLeftFactoring(char productions[MAX][MAX], int numOfProductions) {
    int i, j, k, l;
    char nonTerminal, commonPrefix[MAX], newProduction[MAX][MAX];
    int newProductionCount = 0;
    for (i = 0; i < numOfProductions; i++) {
        nonTerminal = productions[i][0];
        j = 3;
        k = 0;
        while (productions[i][j] != '/' && productions[i][j] != '\0') {
            commonPrefix[k++] = productions[i][j++];
        }
        commonPrefix[k] = '\0';

        // Create new productions
        sprintf(newProduction[newProductionCount++], "%c->%s%c'", nonTerminal, commonPrefix, nonTerminal);
        l = 0;
        while (productions[i][j] != '\0') {
            if (productions[i][j] == '/') {
                j++;
                k = 0;
                while (productions[i][j] != '/' && productions[i][j] != '\0') {
                    commonPrefix[k++] = productions[i][j++];
                }
                commonPrefix[k] = '\0';
                sprintf(newProduction[newProductionCount++], "%c'->%s%c'", nonTerminal, commonPrefix, nonTerminal);
            } else {
                j++;
            }
        }
        sprintf(newProduction[newProductionCount++], "%c'->e", nonTerminal);
    }

    printf("Productions after eliminating left factoring:\n");
    for (i = 0; i < newProductionCount; i++) {
        printf("%s\n", newProduction[i]);
    }
}

