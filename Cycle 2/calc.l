%{
#include "y.tab.h"  
%}

%%
[0-9]+    { yylval = atoi(yytext); return NUMBER; }  
"+"       { return '+'; }  
"-"       { return '-'; }  
"*"       { return '*'; }  
"/"       { return '/'; }  
"("       { return '('; }  
")"       { return ')'; }  
[ \t]+    { /* Ignore spaces and tabs */ }
.         { printf("Unexpected character: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}
