%{
#include <stdio.h>
#include <stdlib.h>

// Declare the yyerror function to avoid implicit declaration warnings
void yyerror(const char *s);

// Declare the yylex function to avoid implicit declaration warnings
int yylex(void);

// Global variable to indicate validity of the arithmetic expression
int flag = 0;
%}

%token NUMBER

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

// Define grammar rules for arithmetic expressions
ArithmeticExpression:
    E {
        printf("\nResult=%d\n", $$);
        return 0;  // End parsing after expression is evaluated
    }
;

E:
    E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E { $$ = $1 / $3; }
  | E '%' E { $$ = $1 % $3; }
  | '(' E ')' { $$ = $2; }
  | NUMBER { $$ = $1; }
;

%%

// Main function
int main() {
    printf("\nEnter Any Arithmetic Expression (Addition, Subtraction, Multiplication, Division, Modulus):\n");
    yyparse();  // Start parsing the input
    if (flag == 0) {
        printf("\nEntered arithmetic expression is Valid\n\n");
    }
    return 0;
}

// Error handling function
void yyerror(const char *s) {
    printf("\nEntered arithmetic expression is Invalid: %s\n\n", s);
    flag = 1;  // Mark as invalid if an error occurs
}