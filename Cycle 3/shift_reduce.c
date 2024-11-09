#include <stdio.h>
#include <string.h>
#define MAX_INPUT 100
#define MAX_STACK 100

void check();

char input[MAX_INPUT], stack[MAX_STACK], action[20];
int input_len, stack_top = -1;

int main() {
    printf("GRAMMAR is:\nE -> E+E | E*E | (E) | id\n");
    printf("Enter input string: ");
    scanf("%s", input);
    input_len = strlen(input);
    printf("\nStack\t\tInput\t\tAction\n");
    for (int i = 0; i < input_len; i++) {
        if (input[i] == 'i' && input[i+1] == 'd') {
            stack[++stack_top] = 'i';
            stack[++stack_top] = 'd';
            stack[stack_top + 1] = '\0';
            printf("$%s\t\t%s$\t\tSHIFT->id\n", stack, input + i + 2);
            check();
            i++;  // Skip the 'd' in the next iteration
        } else {
            stack[++stack_top] = input[i];
            stack[stack_top + 1] = '\0';
            printf("$%s\t\t%s$\t\tSHIFT->%c\n", stack, input + i + 1, input[i]);
            check();
        }
    }
    if (stack_top == 0 && stack[0] == 'E') {
        printf("\nInput string is VALID.\n");
    } else {
        printf("\nInput string is INVALID.\n");
    }
    return 0;
}

void check() {
    int i, j, handle_size;
    char *handle;

    while (1) {
        if (stack_top >=1 && stack[stack_top-1] == 'i' && stack[stack_top] == 'd') {
            handle = "id";
            handle_size = 2;
        } else if (stack_top >= 2 && stack[stack_top-2] == 'E' && stack[stack_top-1] == '+' && stack[stack_top] == 'E') {
            handle = "E+E";
            handle_size = 3;
        } else if (stack_top >= 2 && stack[stack_top-2] == 'E' && stack[stack_top-1] == '*' && stack[stack_top] == 'E') {
            handle = "E*E";
            handle_size = 3;
        } else if (stack_top >= 2 && stack[stack_top-2] == '(' && stack[stack_top-1] == 'E' && stack[stack_top] == ')') {
            handle = "(E)";
            handle_size = 3;
        } else {
            return;  
        }
        stack_top -= handle_size - 1;
        stack[stack_top] = 'E';
        stack[stack_top + 1] = '\0';
        printf("$%s\t\t%s$\t\tREDUCE->%s\n", stack, input + strlen(input), handle);
    }
}
