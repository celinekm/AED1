#include <stdio.h>
#include <stdlib.h>

int compara_crescente(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); 
}
int compara_decrescente(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); 
}

int main() {
    int N;
    scanf("%d", &N);

    int pares[N], impares[N]; 
    int pares_count = 0, impares_count = 0;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        if (num % 2 == 0) {
            pares[pares_count++] = num;
        } else {
            impares[impares_count++] = num;
        }
    }
    qsort(pares, pares_count, sizeof(int), compara_crescente);
    qsort(impares, impares_count, sizeof(int), compara_decrescente);
    for (int i = 0; i < pares_count; i++) {
        printf("%d\n", pares[i]);
    }
    for (int i = 0; i < impares_count; i++) {
        printf("%d\n", impares[i]);
    }
    return 0;
}
