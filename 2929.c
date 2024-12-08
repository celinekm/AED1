#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

typedef struct {
    int valor[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, int v) {
    p->valor[++(p->topo)] = v;
}

int pop(Pilha *p) {
    if (estaVazia(p)) return -1;
    return p->valor[(p->topo)--];
}

int topo(Pilha *p) {
    if (estaVazia(p)) return -1; 
    return p->valor[p->topo];
}

int main() {
    int n;
    scanf("%d", &n);
    Pilha pilhaPrincipal, pilhaMinimos;
    inicializar(&pilhaPrincipal);
    inicializar(&pilhaMinimos);
    char operacao[10];
    for (int i = 0; i < n; i++) {
        scanf("%s", operacao);
        if (strcmp(operacao, "PUSH") == 0) {
            int v;
            scanf("%d", &v);
            push(&pilhaPrincipal, v);
            if (estaVazia(&pilhaMinimos) || v <= topo(&pilhaMinimos)) {
                push(&pilhaMinimos, v);
            }
        } else if (strcmp(operacao, "POP") == 0) {
            if (estaVazia(&pilhaPrincipal)) {
                printf("EMPTY\n");
            } else {
                int removido = pop(&pilhaPrincipal);
                if (removido == topo(&pilhaMinimos)) {
                    pop(&pilhaMinimos);
                }
            }
        } else if (strcmp(operacao, "MIN") == 0) {
            if (estaVazia(&pilhaPrincipal)) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", topo(&pilhaMinimos));
            }
        }
    }
    return 0;
}

