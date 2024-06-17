%{
#include <stdio.h>
%}

%%
[A-Z][a-z]*   { printf("Capital word: %s\n", yysstext); }
.              ;  // Ignore all other characters
%%

int main(int argc, char *argv[]) {
    // Call yylex() to analyze the input
    yylex();
    
    return 0;
}