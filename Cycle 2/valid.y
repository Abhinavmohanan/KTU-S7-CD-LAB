%{
    #include<stdio.h>
    int valid=1;
    int yyerror(char *s);
    int yylex();
%}

%token digit letter

%%
start : letter s
s :     letter s
      | digit s
      |
      ;

%%
int yyerror(char *s) {
    printf("Invalid variable\n");
    valid = 0;
    return 0;
}

int main(){ 
     printf("\nEnter a name to tested for identifier ");
    yyparse();
    if(valid){
    printf("\nIt is an identifier!\n");
    }
}