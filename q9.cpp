#include <stdio.h>
#include <string.h>
#define MAX 10
void eliminateLeftRecursion(char productions[MAX][MAX], int numOfProductions);
int main() {
    int numOfProductions, i;
    char productions[MAX][MAX];
    printf("Enter the number of productions: ");
    scanf("%d", &numOfProductions);
    printf("Enter the productions (e.g., S->(L)/a):\n");
    for (i = 0; i < numOfProductions; i++) {
        scanf("%s", productions[i]);
    }

    eliminateLeftRecursion(productions, numOfProductions);
    return 0;
}
void eliminateLeftRecursion(char productions[MAX][MAX], int numOfProductions) {
    int i, j, k;
    char nonTerminal, alpha[MAX], beta[MAX], newProduction[MAX][MAX];
    int newProductionCount = 0;

    for (i = 0; i < numOfProductions; i++) {
        nonTerminal = productions[i][0];
        if (nonTerminal == productions[i][3]) {
            j = 4;
            k = 0;
            while (productions[i][j] != '/' && productions[i][j] != '\0') {
                alpha[k++] = productions[i][j++];
            }
            alpha[k] = '\0';

            // Find beta
            for (j = 0; j < numOfProductions; j++) {
                if (productions[j][0] == nonTerminal && productions[j][3] != nonTerminal) {
                    k = 4;
                    int l = 0;
                    while (productions[j][k] != '/' && productions[j][k] != '\0') {
                        beta[l++] = productions[j][k++];
                    }
                    beta[l] = '\0';

                    // Create new productions
                    sprintf(newProduction[newProductionCount++], "%c->%s%c'", nonTerminal, beta, nonTerminal);
                    sprintf(newProduction[newProductionCount++], "%c'->%s%c'|e", nonTerminal, alpha, nonTerminal);
                }
            }
        } else {
            // No left recursion
            strcpy(newProduction[newProductionCount++], productions[i]);
        }
    }

    printf("Productions after eliminating left recursion:\n");
    for (i = 0; i < newProductionCount; i++) {
        printf("%s\n", newProduction[i]);
    }
}

