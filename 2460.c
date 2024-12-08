#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50000

int main() {
    int n, m;
    scanf("%d", &n);
    int fila[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &fila[i]);
    }
    scanf("%d", &m);
    int sairam[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &sairam[i]);
    }
    bool saiu[100001] = {false};
    for (int i = 0; i < m; i++) {
        saiu[sairam[i]] = true;
    }
    bool primeiro = true; 
    for (int i = 0; i < n; i++) {
        if (!saiu[fila[i]]) {
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", fila[i]);
            primeiro = false;
        }
    }
    printf("\n");
    return 0;
}

