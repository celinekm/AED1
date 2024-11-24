#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 300

typedef struct {
    char elementos[MAX];
    int topo;
} Pilha;

void inicializaPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int estaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void push(Pilha *pilha, char elemento) {
    if (pilha->topo < MAX - 1) {
        pilha->elementos[++pilha->topo] = elemento;
    }
}

char pop(Pilha *pilha) {
    if (!estaVazia(pilha)) {
        return pilha->elementos[pilha->topo--];
    }
    return '\0';
}
char topo(Pilha *pilha) {
    if (!estaVazia(pilha)) {
        return pilha->elementos[pilha->topo];
    }
    return '\0';
}

int precedencia(char operador) {
    switch (operador) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixoParaPosfixo(char *expressao, char *resultado) {
    Pilha pilha;
    inicializaPilha(&pilha);
    int k = 0;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        if (isalnum(c)) {
            resultado[k++] = c;
        }
        else if (c == '(') {
            push(&pilha, c);
        }
        else if (c == ')') {
            while (!estaVazia(&pilha) && topo(&pilha) != '(') {
                resultado[k++] = pop(&pilha);
            }
            pop(&pilha); 
        }
        else {
            while (!estaVazia(&pilha) && 
                   precedencia(topo(&pilha)) >= precedencia(c)) {
                resultado[k++] = pop(&pilha);
            }
            push(&pilha, c);
        }
    }
    while (!estaVazia(&pilha)) {
        resultado[k++] = pop(&pilha);
    }
    resultado[k] = '\0'; 
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        char expressao[MAX + 1], resultado[MAX + 1];
        fgets(expressao, MAX + 1, stdin);
        expressao[strcspn(expressao, "\n")] = '\0';
        infixoParaPosfixo(expressao, resultado);
        printf("%s\n", resultado);
    }
    return 0;
}

