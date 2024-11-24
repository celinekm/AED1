#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char alunos[N][21];
    for (int i = 0; i < N; i++) {
        scanf("%s", alunos[i]);
    }
    qsort(alunos, N, sizeof(alunos[0]), compare);
    printf("%s\n", alunos[K - 1]);
    srand(time(NULL));
    int S = (rand() % N) + 1;
    printf("\n%d\n", S);
    printf("%s\n", alunos[S - 1]);
    return 0;
}
