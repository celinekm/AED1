#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->key = key;
        newNode->next = NULL;
    }
    return newNode;
}

void insert(Node* hashTable[], int key, int M) {
    int index = key % M;
    Node* newNode = createNode(key);
    if (newNode == NULL) return;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printHashTable(Node* hashTable[], int M) {
    for (int i = 0; i < M; i++) {
        printf("%d ->", i);
        Node* current = hashTable[i];
        while (current != NULL) {
            printf(" %d ->", current->key);
            current = current->next;
        }
        printf(" \\\n");
    }
}

void freeHashTable(Node* hashTable[], int M) {
    for (int i = 0; i < M; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int caso = 0; caso < N; caso++) {
        int M, C;
        scanf("%d %d", &M, &C);
        Node** hashTable = (Node**)malloc(M * sizeof(Node*));
        for (int i = 0; i < M; i++) {
            hashTable[i] = NULL;
        }
        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            insert(hashTable, key, M);
        }
        printHashTable(hashTable, M);

        freeHashTable(hashTable, M);
        free(hashTable);
        if (caso < N - 1) {
            printf("\n");
        }
    }

    return 0;
}
