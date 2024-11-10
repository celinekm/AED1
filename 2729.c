#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista {
    char item[21];
    struct Lista *proximo;
} Lista;

Lista* criarLista(char *item) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    strcpy(novo->item, item);
    novo->proximo = NULL;
    return novo;
}

void inserirOrdenado(Lista **cabeca, char *item) {
    Lista *atual = *cabeca, *anterior = NULL;
    while (atual != NULL && strcmp(atual->item, item) < 0) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual != NULL && strcmp(atual->item, item) == 0) {
        return;
    }
    Lista *novo = criarLista(item);
    if (anterior == NULL) {
        novo->proximo = *cabeca;
        *cabeca = novo;
    } else {
        novo->proximo = atual;
        anterior->proximo = novo;
    }
}

void imprimirLista(Lista *cabeca) {
    Lista *atual = cabeca;
    while (atual != NULL) {
        printf("%s", atual->item);
        if (atual->proximo != NULL) {
            printf(" ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}

void liberarMemoria(Lista *cabeca) {
    Lista *atual = cabeca;
    while (atual != NULL) {
        Lista *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main() {
    int numListas = 0;
    scanf("%d", &numListas);
    getchar();
    Lista *listas[numListas];

    for (int i = 0; i < numListas; i++) {
        char entrada[99999];
        fgets(entrada, 99999, stdin);
        Lista *cabeca = NULL;
        char *item = strtok(entrada, " \n");
        while (item != NULL) {
            inserirOrdenado(&cabeca, item);
            item = strtok(NULL, " \n");
        }
        listas[i] = cabeca;
    }

    for (int i = 0; i < numListas; i++) {
        imprimirLista(listas[i]);
        liberarMemoria(listas[i]);
    }

    return 0;
}
