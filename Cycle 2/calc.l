%{
#include <stdio.h>
#include <stdlib.h>  // For atoi
#include "y.tab.h"   // Include Yacc-generated header
extern int yylval;   // Declare yylval to hold the value of tokens
%}

%%


[0-9]+ {
    yylval = atoi(yytext);  // Convert string to integer
    return NUMBER;          // Return the NUMBER token
}


[\t] ; 


[\n] return 0;          


. return yytext[0];   

%%

// Function called at the end of input
int yywrap() {
    return 1; // Indicate no more input
}