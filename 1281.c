#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[51];
    double preco;
} Produto;

int main() {
    int N; 
    scanf("%d", &N); 
    while (N--) {
        int M; 
        scanf("%d", &M);
        Produto produtos[100];
        for (int i = 0; i < M; i++) {
            scanf("%s %lf", produtos[i].nome, &produtos[i].preco);
        }
        int P; 
        scanf("%d", &P);
        double total = 0.0; 
        for (int i = 0; i < P; i++) {
            char nomeProduto[51];
            int quantidade;
            scanf("%s %d", nomeProduto, &quantidade);
            for (int j = 0; j < M; j++) {
                if (strcmp(produtos[j].nome, nomeProduto) == 0) {
                    total += produtos[j].preco * quantidade;
                    break;
                }
            }
        }  
        printf("R$ %.2f\n", total);
    }
    
    return 0;
}
