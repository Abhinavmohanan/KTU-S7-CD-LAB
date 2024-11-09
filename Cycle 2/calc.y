%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *s);
int yylex(void);
%}

%token NUMBER

%%
start:  expression             { printf(" Result is : %d\n", $1); }
        ;
expression:
      expression '+' term         { $$ = $1 + $3; }
    | expression '-' term         { $$ = $1 - $3; }
    | term                        { $$ = $1; }
    ;
term:
      term '*' factor             { $$ = $1 * $3; }
    | term '/' factor             { $$ = $1 / $3; }
    | factor                      { $$ = $1; }
    ;
factor:
      '(' expression ')'          { $$ = $2; }     
    | NUMBER                      { $$ = $1; }
    ;
%%

int main() {
    printf("Enter an arithmetic expression: ");
    yyparse();   
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
