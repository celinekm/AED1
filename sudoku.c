#include <stdio.h>

int verifica(int x, int V[9][9], int l, int c){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (V[i][c] == x || V[l][j]== x)
                return 0;
        }
    }
    int blocolinha = (l/3)*3, blococoluna = (c/3)*3;
    for (int i= blocolinha; i< blocolinha+3; i++){
        for (int j=blococoluna; j<blococoluna+3; j++){
            if (V[i][j]==x)
                return 0;
        }
    }
    return 1;
}
int main(){
    int jogo=0, V[9][9]={0}, x, instancia,n=1;
    scanf ("%d", &jogo);
    while (jogo > 0){
        for (int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                scanf ("%d", &x);
                if (verifica(x, V, i,j)){
                    V[i][j] = x ;
                }
                else {
                    instancia = 1;
                }
            }
        }
         printf("Instancia %d\n", n);
        if(!instancia){
            printf("SIM\n\n");
        }
        else{
            printf("NAO\n\n");
        }

        instancia = 0;
        jogo--;
        n++;
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
              V[i][j] = 0;
            }
        }
    }
