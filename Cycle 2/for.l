%{
#include "y.tab.h"
%}

%%
for					return FOR;
[\(\)]					return PARANTHESIS;
[a-zA-Z0-9]*				return OPERAND;
"="|"<"|">"|">="|"<="|"=="|"++"|"--"	return OPERATOR;
\;					return SEMICOLON;
,					return COMMA;
\n					return NEWLINE;
.					;
%%

int yywrap()
{
	return 1;
}