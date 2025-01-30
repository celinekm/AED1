#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, k, m;
    while (scanf("%d %d %d", &N, &k, &m) && (N || k || m)) {
        int candidatos[20];
        for (int i = 0; i < N; i++) {
            candidatos[i] = i + 1;
        }
        
        int restantes = N, i = -1, j = N;
        int primeiro = 1;
        
        while (restantes > 0) {
            for (int a = 0; a < k; a++) {
                do {
                    i = (i + 1) % N;
                } while (candidatos[i] == 0);
            }
            
            for (int b = 0; b < m; b++) {
                do {
                    j = (j - 1 + N) % N;
                } while (candidatos[j] == 0);
            }
            
            if (!primeiro) printf(",");
            printf("%3d", candidatos[i]);
            primeiro = 0;
            restantes--;
            
            if (i != j) {
                printf("%3d", candidatos[j]);
                restantes--;
            }
            
            candidatos[i] = candidatos[j] = 0;
        }
        printf("\n");
    }
    return 0;
}
