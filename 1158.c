#include <stdio.h>

int main() {
    int N;  
    scanf("%d", &N);
    while (N--) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        if (X % 2 == 0) {
            X++;
        }
        int soma = 0;
        for (int i = 0; i < Y; i++) {
            soma += X;
            X += 2; 
        }
        printf("%d\n", soma); 
    }
    return 0;
}
