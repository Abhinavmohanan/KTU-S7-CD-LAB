/* Lex program to accept strings which does not contain first four characters of your name as substring  */
%{
#include <stdio.h>
%}

%%
.*(?i:abhi).*\n   { printf("Not Accepted\n"); }
.       {/* do nothing */}
\n     { printf("Accepted\n"); }
%% 

int main(int argc, char **argv) {
    printf("Enter a string (or type 'Ctrl + d' to quit): \n");
     yylex();
    return 0;
}

int yywrap() {
    return 1;
}
