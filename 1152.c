#include <stdio.h>
#include <stdlib.h>

typedef struct Aresta {
    int u, v, peso;
} Aresta;

typedef struct UnionFind {
    int *pai, *rank;
    int n;
} UnionFind;

UnionFind* criar_union_find(int n) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->n = n;
    uf->pai = (int*)malloc(n * sizeof(int));
    uf->rank = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->pai[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

int find(UnionFind* uf, int x) {
    if (uf->pai[x] != x) {
        uf->pai[x] = find(uf, uf->pai[x]); 
    }
    return uf->pai[x];
}

void unite(UnionFind* uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);
    if (rootX != rootY) {
        if (uf->rank[rootX] > uf->rank[rootY]) {
            uf->pai[rootY] = rootX;
        } else if (uf->rank[rootX] < uf->rank[rootY]) {
            uf->pai[rootX] = rootY;
        } else {
            uf->pai[rootY] = rootX;
            uf->rank[rootX]++;
        }
    }
}

int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

long long kruskal(Aresta* arestas, int m, int n) {
    UnionFind* uf = criar_union_find(m);
    qsort(arestas, n, sizeof(Aresta), comparar);

    long long custo_mst = 0;
    int arestas_usadas = 0;

    for (int i = 0; i < n && arestas_usadas < m - 1; i++) {
        Aresta a = arestas[i];
        if (find(uf, a.u) != find(uf, a.v)) {
            unite(uf, a.u, a.v);
            custo_mst += a.peso;
            arestas_usadas++;
        }
    }

    free(uf->pai);
    free(uf->rank);
    free(uf);

    return custo_mst;
}

int main() {
    int m, n;

    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;

        Aresta* arestas = (Aresta*)malloc(n * sizeof(Aresta));
        long long custo_total = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
            custo_total += arestas[i].peso;
        }
        long long custo_mst = kruskal(arestas, m, n);
        printf("%lld\n", custo_total - custo_mst);

        free(arestas);
    }
    return 0;
}
