#include <stdio.h>
#include <string.h>

int leds_por_digito(char digito) {
    switch (digito) {
        case '0': return 6;
        case '1': return 2;
        case '2': return 5;
        case '3': return 5;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 3;
        case '8': return 7;
        case '9': return 6;
        default: return 0; 
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char numero[10101];  
        scanf("%s", numero);     
        int total_leds = 0;
        for (int j = 0; numero[j] != '\0'; j++) {
            total_leds += leds_por_digito(numero[j]);  
        }
        printf("%d leds\n", total_leds);
    }   
    return 0;
}
