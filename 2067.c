#include <stdio.h>
#include <stdbool.h>

#define MAX 200

int matriz[MAX][MAX];
int prefixo[MAX + 1][MAX + 1];
void calcularPrefixos(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefixo[i][j] = matriz[i - 1][j - 1] + prefixo[i - 1][j] + prefixo[i][j - 1] - prefixo[i - 1][j - 1];
        }
    }
}

bool existeQuadradoSemZeros(int n, int m, int s) {
    for (int i = s; i <= n; i++) {
        for (int j = s; j <= m; j++) {
            int soma = prefixo[i][j] - prefixo[i - s][j] - prefixo[i][j - s] + prefixo[i - s][j - s];
            if (soma == s * s) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m, q;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int valor;
            scanf("%d", &valor);
            matriz[i][j] = (valor != 0 ? 1 : 0);
        }
    }
    calcularPrefixos(n, m);
    scanf("%d", &q);
    while (q--) {
        int s;
        scanf("%d", &s);
        if (existeQuadradoSemZeros(n, m, s)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
