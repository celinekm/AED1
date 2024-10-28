#include <stdio.h>

int verifica( int V[9][9], int l, int c, int numero){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(V[l][j] == numero || V[i][c] == numero)
            return 0;
        }
    }
    for(int i=(l/3)*3; i<3; i++){
        for(int j=(c/3)*3; j<3: j++){
            if(V[i][j]== numero)
            return 0;
        }
    }
    return 1;
}

int main(){
    int M[9][9] ={0}, valido=0, instancia=0, numero;
    scanf("%d", &instancia);
    for(int i=0; i<instancia; i++){
        for(int j=0; j<9; j++){
            for( int k=0; k<9; k++){
                scanf("%d", &numero);
                if(!verifica(M,j,k,numero)){
                    valido = 1;
                }
            }
        }
        if(valido == 1)
            printf("instancia %d\nNAO", i+1);
        if(valido == 0)
            printf("instancia %d\nSIM", i+1)
    }
    
}
