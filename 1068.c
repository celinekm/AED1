#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct No {
    char dado;
    struct No *prox;
} No;


void empilhar(No **topo, char valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = *topo;
    *topo = novo;
}

void desempilhar(No **topo) {
    if (*topo != NULL) {
        No *temp = *topo;
        *topo = (*topo)->prox;
        free(temp);
    }
}

int esta_vazia(No *topo) {
    return topo == NULL;
}

void verifica(const char *expressao) {
    No *pilha = NULL; 

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            empilhar(&pilha, '('); 
        } else if (expressao[i] == ')') {
            if (esta_vazia(pilha)) {  
              printf("incorrect\n");
              return;
            }
            desempilhar(&pilha); 
        }
    }

    if (esta_vazia(pilha)) {
        printf("correct\n"); 
    } else {
        printf("incorrect\n"); 
    }
    while (!esta_vazia(pilha)) {
        desempilhar(&pilha);
    }
}

int main() {
    char expressao[MAX]; 
    while (fgets(expressao, MAX, stdin) !=NULL){
        expressao[strcspn(expressao, "\n")] = '\0'; 
        verifica(expressao); 
    }
    return 0;
}

