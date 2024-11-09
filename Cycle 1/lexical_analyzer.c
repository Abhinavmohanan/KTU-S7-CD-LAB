#include <stdio.h>
#include <string.h>

char line[100];

int is_operator(char c)
{
    switch (c)
    {
        case '+':   
        case '-':   
        case '*':   
        case '/':   
        case '=':   
            printf("%c - Operator\n", c);
            return 1;
    }
    return 0;
}

int is_delimiter(char c)
{
    switch (c)
    {
        case '{':
        case '}':
        case '(':
        case ')':
        case '[':
        case ']':
        case ',':
        case ';':
            printf("%c - Delimiter\n", c);
            return 1;
    }
    return 0;
}

int is_keyword(char buffer[]){
	char keywords[32][10] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
	int i;
	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			return 1;
		}
	}
return 0;
}

void main()
{
    char c;
    FILE *f = fopen("input.txt", "r");

    while (fgets(line, sizeof(line), f))
    {
        int flag1 = 0;
        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] == '/' && line[i + 1] == '/')
            {
                flag1 = 1;
                break;
            }       
        }
        if (flag1)
            continue;        
        int flag2 = 0;
        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] == '/' && line[i + 1] == '*')
            {
                while (fgets(line, sizeof(line), f))
                {
                    for (int j = 0; j < strlen(line); j++)
                    {
                        if (line[j] == '*' && line[j + 1] == '/')
                            flag2 = 1;
                    }
                    if (flag2)
                        break;
                }
            }
        }
        if (flag2)
            continue;
        printf("\n%s\n", line);
        char token[100];
        int index = 0;
        strcpy(token, "");

        for (int i = 0; i < strlen(line); i++)
        {
            if (is_operator(line[i]) || is_delimiter(line[i]) || line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
            {
                if (strcmp(token, "") != 0)
                {
                    if (is_keyword(token))
                        printf("%s - Keyword\n", token);
                    else  
                        printf("%s - Identifier\n", token);
                    strcpy(token, "");
                    index = 0;
                }
            }
            else  
            {
                token[index++] = line[i];
                token[index] = '\0';
            }
        }
    }
    fclose(f);
}

