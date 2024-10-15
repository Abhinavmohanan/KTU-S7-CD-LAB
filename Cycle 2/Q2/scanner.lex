%{
#include "identifier.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]*  { return LETTER; }
[0-9]+                { return DIGIT; }
[ \t]                 ; // ignore whitespace
\n                    { return '\n'; }
.                     { return yytext[0]; } // catch all other characters
%%

int yywrap() {
    return 1;
}