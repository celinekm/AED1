#include <stdio.h>
#include <string.h>


int calcularPaginas(char palavras[1000][71], int N, int L, int C) {
    int linhaAtual = 0;    
    int numLinhas = 1;     
    int numPaginas = 1;    
    
    for (int i = 0; i < N; i++) {
        int tamPalavra = strlen(palavras[i]);
        if (linhaAtual == 0) {
            linhaAtual = tamPalavra;
        }
        else if (linhaAtual + tamPalavra + 1 <= C) {
            linhaAtual += tamPalavra + 1;
        }
        else {
            numLinhas++;
            if (numLinhas > L) {
                numPaginas++;
                numLinhas = 1;
            }
            linhaAtual = tamPalavra;
        }
    }
    
    return numPaginas;
}

int main() {
    int N, L, C;
    char palavras[1000][71];
    
    while (scanf("%d %d %d", &N, &L, &C) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%s", palavras[i]);
        }
        int resultado = calcularPaginas(palavras, N, L, C);
        printf("%d\n", resultado);
    }
    
    return 0;
}
