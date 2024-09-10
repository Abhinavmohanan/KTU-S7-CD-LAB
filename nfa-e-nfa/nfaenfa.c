#include<stdio.h>
#include<stdbool.h>
#include <string.h> 

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

void printDel(){
    for(int i=0;i<no;i++){
        printf("\n");
        for(int j=0;j<no;j++){
            printf("%c ",dels[i][j]);
        }
    }
    printf("\n");
}


int main(){
    int trans,s1,s2;
    char symbol;

    memset(dels,'x',20*20*sizeof(int));

    printf("\nEnter no. of states (max 20): ");
    scanf("%d",&no);
    printf("\nEnter no. of transitions : ");
    scanf("%d",&trans);
    printf("\nEnter start state, symbol (0 or 1) , end state: \n");
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
                    if(current[k] == 1 && dels[k][j] == 'x'){ 
                        dels[k][j] = 'e'; //reachable (closure)
                    }
                }
                getEpsilon(j);
            } 
        }
        current[i] = 0;
    }
    printDel();
    for(int i = 0 ; i < no; i++){        
        getEpsilon(i);
    } 
    printf("Closure");
    display();
    printDel();


    void nfawithoute(){
        //δ'(q0, a) = ε-closure(δ(δ^(q0, ε),a))  = ε-closure(δ(ε-closure(q0),a))
        for(int i=0 ; i<no;i++){
            for(int s=0; s<2 ; s++){ //only two input symbol considered
                memset(current,0,no*sizeof(int));
                printf("\nδ(q%d,%d) = { ",i,s);
                for(int j = 0 ; j < no; j++){ // closure
                    if(dels[i][j]  == 'e' || i == j){
                        for(int k = 0 ; k < no; k++){ //transition on closure
                            if((int)dels[j][k]  == s+48){
                                current[k] = 1;
                            }
                        }
                    }
                }

                for(int j = 0 ; j < no; j++){ //transition on closure
                    if(current[j]  == 1){
                        printf("q%d ",j);
                        for(int k = 0 ; k < no; k++){ //last closure
                            if(dels[j][k]  == 'e' && j!=k){
                                printf("q%d ",k);
                            }
                        }
                    }
                }
                printf(" }");
            }
        }
    }

    nfawithoute();
}