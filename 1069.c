#include <stdio.h>
#include <string.h>

int contaDiamantes(char *linha) {
    int diamantes = 0;
    int contadoraberto = 0; 

    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '<') {
            contadoraberto++; 
        } else if (linha[i] == '>') {
            if (contadoraberto > 0) {
                diamantes++;   
                contadoraberto--; 
            }
        }
    }

    return diamantes;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); 
    
    for (int i = 0; i < N; i++) {
        char linha[1001]; 
        fgets(linha, 1001, stdin);
        linha[strcspn(linha, "\n")] = '\0';
        int resultado = contaDiamantes(linha);
        printf("%d\n", resultado);
    }

    return 0;
}
