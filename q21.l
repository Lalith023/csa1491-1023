%{
#include <stdio.h>
%}

%%

[a-zA-Z]+ { printf("Word: %s\n", yytext); }
[0-9]+ { printf("Number: %s\n", yytext); }
.|\n { }

%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("Enter input text:\n");
    yylex();
    return 0;
}
