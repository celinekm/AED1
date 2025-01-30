#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char palavra[17];
    int valor;
} PalavraValor;

PalavraValor dicionario[1000];
int M, N;

int busca_valor(const char *palavra) {
    for (int i = 0; i < M; i++) {
        if (strcmp(dicionario[i].palavra, palavra) == 0) {
            return dicionario[i].valor;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        scanf("%s %d", dicionario[i].palavra, &dicionario[i].valor);
    }
    
    char palavra[17];
    int salario;
    for (int i = 0; i < N; i++) {
        salario = 0;
        while (scanf("%s", palavra) && strcmp(palavra, ".") != 0) {
            salario += busca_valor(palavra);
        }
        printf("%d\n", salario);
    }
    return 0;
}
