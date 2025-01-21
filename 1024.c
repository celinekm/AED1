#include <stdio.h>
#include <string.h>

void criptografar(char *texto) {
    int n = strlen(texto);
    char resultado[n + 1]; 
    for (int i = 0; i < n; i++) {
        if ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z')) {
            resultado[i] = texto[i] + 3;
        } else {
            resultado[i] = texto[i];
        }
    }
    resultado[n] = '\0'; 
    for (int i = 0; i < n / 2; i++) {
        char temp = resultado[i];
        resultado[i] = resultado[n - 1 - i];
        resultado[n - 1 - i] = temp;
    }
    for (int i = n / 2; i < n; i++) {
        resultado[i] = resultado[i] - 1;
    }
    strcpy(texto, resultado);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); 
    for (int i = 0; i < N; i++) {
        char texto[1001]; 
        fgets(texto, sizeof(texto), stdin);
        int len = strlen(texto);
        if (texto[len - 1] == '\n') {
            texto[len - 1] = '\0';
        }
        criptografar(texto);
        printf("%s\n", texto);
    }
    return 0;
}
