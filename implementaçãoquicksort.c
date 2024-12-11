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
    int V[MAX];
    for (int k = 0; k<3; k++){
        printf("repeticao %d \n\n", k+1);
        for (int n = 0; n <= MAX; n += 20000) {
        for (int i = 0; i < n; i++) {
            V[i] = rand() % 1000000;
        }
        clock_t comeco = clock();
        mergeSort(V, 0, n - 1);
        clock_t fim = clock();
        double demorou = ((double)(fim - comeco)) / CLOCKS_PER_SEC;
        printf("N = %d, Tempo = %f segundos\n", n, demorou);
        }
    }
    return 0;
}
