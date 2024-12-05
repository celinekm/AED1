#include <stdio.h>

void processarPilha(int n) {
    int pilha[50000], descartadas[50000];
    int topo = 0, base = 0; 
    int qtddescartadas = 0;
    for (int i = 1; i <= n; i++) {
        pilha[base++] = i;
    }
    while (base - topo > 1) {
        descartadas[qtddescartadas++] = pilha[topo++]; 
        pilha[base++] = pilha[topo++];                
    }
    printf("Discarded cards:");
    for (int i = 0; i < qtddescartadas; i++) {
        if (i == 0) {
            printf(" %d", descartadas[i]);
        } else {
            printf(", %d", descartadas[i]);
        }
    }
    printf("\n");
    printf("Remaining card: %d\n", pilha[topo]);
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        processarPilha(n);
    }

    return 0;
}
