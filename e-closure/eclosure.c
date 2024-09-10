#include<stdio.h>
#include<stdbool.h>

char dels[20][20] = {'x'};
bool visited[20] = {false};
int current[20] = {0};
int no = 20;
void display(){
    for(int i = 0 ; i < no; i++){  
        printf("\nq%d = { q%d",i,i);
        for(int j = 0 ; j < no; j++){
            if(dels[i][j] == 'e' && i != j){
                printf(" q%d",j);
            }
        }
        printf(" }");
    }
    printf("\n");
    return;
}

int main(){
    int trans,s1,s2;
    char symbol;
    printf("\nEnter no. of states (max 20): ");
    scanf("%d",&no);
    printf("\nEnter no. of transitions : ");
    scanf("%d",&trans);
    printf("\nEnter start state, symbol , end state: \n");
    for(int i = 0 ; i < trans; i++){
        scanf("%d",&s1);
        scanf("%c",&symbol); //space
        scanf("%c",&symbol);
        scanf("%d",&s2);
        dels[s1][s2] = symbol;
    }



    void getEpsilon(int i){
        if(visited[i]) return;
        visited[i] = 1;
        current[i] = 1;
        for(int j = 0 ; j < no; j++){
            if(dels[i][j] == 'e'){
                for(int k=0; k < no; k++){
                    if(current[k] == 1 ){ 
                        dels[k][j] = 'c'; //reachable (closure)
                    }
                }
                getEpsilon(j);
            } 
        }
        current[i] = 0;
    }

    for(int i = 0 ; i < no; i++){        
        getEpsilon(i);
    } 

    display();
}