#include <stdio.h>
#include <string.h>


int podeLigar(char a, char b) {
    return (a == 'B' && b == 'S') || (a == 'S' && b == 'B') ||
           (a == 'C' && b == 'F') || (a == 'F' && b == 'C');
}

int calcularLigacoes(char *rna) {
    char pilha[301]; 
    int topo = -1;     
    int ligacoes = 0;  
    int n = strlen(rna);

    for (int i = 0; i < n; i++) {
        if (topo >= 0 && podeLigar(pilha[topo], rna[i])) {
            topo--;
            ligacoes++;
        } else {
            pilha[++topo] = rna[i];
        }
    }

    return ligacoes;
}

int main() {
    char rna[301];
    while (scanf("%s", rna) != EOF) {
        printf("%d\n", calcularLigacoes(rna));
    }

    return 0;
}
