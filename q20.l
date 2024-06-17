%{
#include <stdio.h>
%}

digit [0-9]

%%

{digit}+ { printf("%s is a constant\n", yytext); }
.|\\n { }

%%

int yywrap(void) {
    return 1;
}

int main(void) {
    FILE *f;
    char filename[100];
    
    printf("Enter File Name: ");
    scanf("%s", filename);
    
    f = fopen(filename, "r");
    yyin = f;
    yylex();
    
    fclose(yyin);
    return 0;
}
