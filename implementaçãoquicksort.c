#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 400000

void quickSort(int v[], int low, int high) {
    if (low < high) {
        int pivo = v[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (v[j] <= pivo) {
                i++;
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
        int temp = v[i + 1];
        v[i + 1] = v[high];
        v[high] = temp;
        int pi = i + 1;
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

int main() {
    clock_t t; 
    int vetor[MAX];
    srand((unsigned)time(NULL));
    for (int a = 0; a < MAX; a++)
        vetor[a] = rand() % MAX;
    t = clock(); 
    quickSort(vetor, 0, MAX - 1);
    t = clock() - t; 
    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000))); 
    return 0;
}
