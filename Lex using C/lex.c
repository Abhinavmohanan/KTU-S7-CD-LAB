#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
char keywords[32][20] = {
    "int", "char", "float", "double", "void", "struct", "union", "enum",
    "static", "extern", "const", "volatile", "unsigned", "signed", "short",
    "long", "typedef", "return", "continue", "break", "for", "while", "do",
    "if", "else", "switch", "case", "default", "goto", "sizeof", "typedef",
   	"printf"
};

bool isKeyword(char *key){
	for(int i = 0; i < 20;i++){
		if(strcmp(key,keywords[i]) == 0){
			return true;		
		}	
	}
	return false;
}

bool isNumber(char *key){
	for(int i = 0; key[i] != '\0';i++){
		if(isdigit(key[i]) == 0){
			return false;		
		}	
	}
	return true;
}

bool isOperator(char op){
	switch(op){
		case '=':
		case '+':
		case '-':
		case '>':
		case '<':
		case '.':
		case '*':
		case '/':
		case ';':
		case '%':
			return true;
		default:
			return false;
	}
}

bool isSpecial(char ch) {
    switch(ch) {
        case ';':
        case '{':
        case '}':
        case '(':
        case ')':
        case '?':
        case '@':
	case ',':
        case '!':
            return true;
        default:
            return false;
    }
}




void main(){
	FILE *src = fopen("input.txt","r");
	char token,temp[200];
	int i = 0;
	while((token=fgetc(src))!=EOF){
		if(token == '\n' || token == ' '){
			continue;		
		}
		else if(isSpecial(token)){
			printf("Special : %c\n",token);
		}else if(isOperator(token)){
			printf("Operator : %c\n",token);
		}else{
			i = 0;
			temp[i] = token;
			i++;
			token=fgetc(src);
			while(!(token == EOF || token == '\n' || token == ' ') && !isSpecial(token) && !isOperator(token)){
				temp[i] = token;
				i++;
				token=fgetc(src);
			}	
			temp[i] = '\0';
			if(isNumber(temp)==true){
				printf("Constant : %s\n",temp);
			}
			else if(isKeyword(temp)==true){
				printf("Keyword : %s\n",temp);
			}else{
				printf("Identifier : %s\n",temp);
			}

			//check token
			if(token == EOF){
				break;		
			}else{
				fseek(src, -1, SEEK_CUR);		
			}
		}
	}
}

