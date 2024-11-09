%{
#include <stdio.h>
#include <string.h>

char name[100];
char prefix[100]; 

void recognize_string(const char *input_string) {
    if (strstr(input_string, prefix) == NULL) {
        printf("%s is recognized\n", input_string);
    } else {
        printf("%s is not recognized\n", input_string);
    }
}
%}

%%
[A-Za-z]+  { recognize_string(yytext); } 
\n         { /* Ignore newlines */ }
.          { /* Ignore any other character */ }
%%

int main() {
    printf("Enter the name: ");
    fgets(name, 100, stdin);  
    name[strcspn(name, "\n")] = 0; 
    int prefix_len;
    prefix_len=4;
    strncpy(prefix, name, prefix_len);
    prefix[prefix_len] = '\0'; 
    printf("Enter input strings (Ctrl+D to stop):\n");
    yylex();  
    return 0;
}

int yywrap() {
    return 1;
}
