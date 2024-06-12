#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NON_TERMINALS 10
#define MAX_TERMINALS 10

// Define the grammar
char nonTerminals[MAX_NON_TERMINALS] = {'E', 'T', 'F'};
char terminals[MAX_TERMINALS] = {'+', '*', '(', ')', 'id'};

// Initialize trailing sets
char trailingSets[MAX_NON_TERMINALS][MAX_TERMINALS];

// Initialize the grammar rules
char grammar[][10] = {
    "E+T", "T",       // E -> E + T | T
    "T*F", "F",       // T -> T * F | F
    "(E)", "id",      // F -> (E) | id
};

// Function to compute trailing sets
void computeTrailingSets() {
    int i, j, k;
    bool changed;

    // Initialize trailing sets
    for (i = 0; i < MAX_NON_TERMINALS; i++) {
        for (j = 0; j < MAX_TERMINALS; j++) {
            trailingSets[i][j] = '\0';
        }
    }

    // Initialize trailing set for '$' (end marker)
    trailingSets[0][4] = '$';

    do {
        changed = false;

        for (i = 0; i < MAX_NON_TERMINALS; i++) {
            for (j = 0; j < MAX_TERMINALS; j++) {
                if (trailingSets[i][j] == '\0') {
                    for (k = 0; k < MAX_NON_TERMINALS; k++) {
                        char* pos = strstr(grammar[k], &nonTerminals[i]);
                        if (pos != NULL && pos[1] == '\0') {
                            // Add trailing set of k to i
                            for (int t = 0; t < MAX_TERMINALS; t++) {
                                if (trailingSets[k][t] != '\0' && trailingSets[i][t] == '\0') {
                                    trailingSets[i][t] = trailingSets[k][t];
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    } while (changed);
}

int main() {
    computeTrailingSets();

    // Print trailing sets
    printf("Trailing Sets:\n");
    for (int i = 0; i < MAX_NON_TERMINALS; i++) {
        printf("%c: ", nonTerminals[i]);
        for (int j = 0; j < MAX_TERMINALS; j++) {
            if (trailingSets[i][j] != '\0') {
                printf("%c ", trailingSets[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

