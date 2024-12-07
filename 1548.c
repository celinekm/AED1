#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nota;
    int posicao;
} Aluno;

int comparar(const void *a, const void *b) {
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    return alunoB->nota - alunoA->nota;
}

int main() {
    int n;
    scanf("%d", &n); 
    while (n--) {
        int m;
        scanf("%d", &m); 
        Aluno alunos[m];
        for (int i = 0; i < m; i++) {
            scanf("%d", &alunos[i].nota);
            alunos[i].posicao = i;
        }
        Aluno ordenados[m];
        for (int i = 0; i < m; i++) {
            ordenados[i] = alunos[i];
        }
        qsort(ordenados, m, sizeof(Aluno), comparar);
        int mesmosLugares = 0;
        for (int i = 0; i < m; i++) {
            if (ordenados[i].posicao == i) {
                mesmosLugares++;
            }
        }
        printf("%d\n", mesmosLugares);
    }

    return 0;
}
