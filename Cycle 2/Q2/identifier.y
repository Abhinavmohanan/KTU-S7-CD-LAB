%{
#include <stdio.h>
%}

%token LETTER DIGIT

%%

// Define your grammar
variable:
    LETTER rest { printf("Valid variable\n"); }
    ;

rest:
    | rest LETTER
    | rest DIGIT
    ;

%%

// Main function to run the parser
int main() {
    printf("Enter a variable: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Invalid variable");
    return 0;
}