#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

typedef struct {
    int id; 
    long long tempoLivre; 
} Funcionario;

int encontrarMenor(Funcionario funcionarios[], int n) {
    int menor = 0;
    for (int i = 1; i < n; i++) {
        if (funcionarios[i].tempoLivre < funcionarios[menor].tempoLivre ||
            (funcionarios[i].tempoLivre == funcionarios[menor].tempoLivre && funcionarios[i].id < funcionarios[menor].id)) {
            menor = i;
        }
    }
    return menor;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int v[n];
    int c[m];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &c[i]);
    }
    Funcionario funcionarios[n];
    for (int i = 0; i < n; i++) {
        funcionarios[i].id = i + 1;
        funcionarios[i].tempoLivre = 0;
    }
    for (int i = 0; i < m; i++) {
        int menor = encontrarMenor(funcionarios, n);
        funcionarios[menor].tempoLivre += (long long)v[menor] * c[i];
    }
    long long tempoTotal = 0;
    for (int i = 0; i < n; i++) {
        if (funcionarios[i].tempoLivre > tempoTotal) {
            tempoTotal = funcionarios[i].tempoLivre;
        }
    }
    printf("%lld\n", tempoTotal);
    return 0;
}

