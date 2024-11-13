#include <stdio.h>
#include <string.h>

#define MAXA 1000
#define MAXN 21

int main() {
    char amigos[MAXA][MAXN];
    char novosamigos[MAXA][MAXN];
    char lista[MAXA][MAXN];
    char amigoss[MAXN];
    int contagem = 0, novacont = 0, tempcont = 0;

    char linha[20000];
    fgets(linha, sizeof(linha), stdin);
    char *token = strtok(linha, " \n");
    while (token != NULL) {
        strcpy(amigos[contagem++], token);
        token = strtok(NULL, " \n");
    }
    fgets(linha, sizeof(linha), stdin);
    token = strtok(linha, " \n");
    while (token != NULL) {
        strcpy(novosamigos[novacont++], token);
        token = strtok(NULL, " \n");
    }

    fgets(amigoss, sizeof(amigoss), stdin);
    amigoss[strcspn(amigoss, "\n")] = '\0'; 

    int insere = 0;
    for (int i = 0; i < contagem; i++) {
        if (strcmp(amigos[i], amigoss) == 0) {
            for (int j = 0; j < novacont; j++) {
                strcpy(lista[tempcont++], novosamigos[j]);
            }
            inserted = 1;
        }
        strcpy(lista[tempcont++], amigos[i]);
    }

    if (!insere) {
        for (int i = 0; i < novacont; i++) {
            strcpy(lista[tempcont++], novosamigos[i]);
        }
    }

    for (int i = 0; i < tempcont; i++) {
        if (i > 0) printf(" ");
        printf("%s", lista[i]);
    }
    printf("\n");

    return 0;
}
