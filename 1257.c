#include <stdio.h>
#include <string.h>

int calcular_hash(int L) {
    int hash = 0;
    for (int i = 0; i < L; i++) {
        char linha[51];  
        scanf("%s", linha);  
        int tam = strlen(linha);
        for (int j = 0; j < tam; j++) {
            int pos_alfabeto = linha[j] - 'A'; 
            int valor = pos_alfabeto + i + j;  
            hash += valor;  
        }
    }
    return hash;
}

int main() {
    int N;
    scanf("%d", &N);  
    while (N--) {
        int L;
        scanf("%d", &L);  
        int hash = calcular_hash(L);
        printf("%d\n", hash);  
    }   
    return 0;
}
