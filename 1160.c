#include <stdio.h>

int main() {
    int T;  
    scanf("%d", &T);
    while (T--) {
        int PA, PB;
        float G1, G2;
        scanf("%d %d %f %f", &PA, &PB, &G1, &G2);   
        int anos = 0;
        while (PA <= PB) {
            PA += (int)(PA * G1 / 100);  
            PB += (int)(PB * G2 / 100);  
            anos++;
            if (anos > 100) {
                printf("Mais de 1 seculo.\n");
                break;
            }
        }
        if (anos <= 100) {
            printf("%d anos.\n", anos);
        }
    }
    return 0;
}
