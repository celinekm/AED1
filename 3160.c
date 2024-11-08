#include <stdio.h>
#include <string.h>

#define MAX_FRIENDS 1000
#define MAX_NAME_LENGTH 21

int main() {
    char current_friends[MAX_FRIENDS][MAX_NAME_LENGTH];
    char new_friends[MAX_FRIENDS][MAX_NAME_LENGTH];
    char temp_list[MAX_FRIENDS][MAX_NAME_LENGTH];
    char target_friend[MAX_NAME_LENGTH];
    int current_count = 0, new_count = 0, temp_count = 0;

    // Ler a lista atual de amigos
    char line[20000];
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " \n");
    while (token != NULL) {
        strcpy(current_friends[current_count++], token);
        token = strtok(NULL, " \n");
    }

    // Ler a nova lista de amigos
    fgets(line, sizeof(line), stdin);
    token = strtok(line, " \n");
    while (token != NULL) {
        strcpy(new_friends[new_count++], token);
        token = strtok(NULL, " \n");
    }

    // Ler o nome do amigo que receberá a indicação, ou "nao"
    fgets(target_friend, sizeof(target_friend), stdin);
    target_friend[strcspn(target_friend, "\n")] = '\0'; // Remover o newline

    // Verificar se o nome do amigo está na lista atual
    int inserted = 0;
    for (int i = 0; i < current_count; i++) {
        if (strcmp(current_friends[i], target_friend) == 0) {
            // Inserir novos amigos antes do amigo indicado
            for (int j = 0; j < new_count; j++) {
                strcpy(temp_list[temp_count++], new_friends[j]);
            }
            inserted = 1;
        }
        strcpy(temp_list[temp_count++], current_friends[i]);
    }

    // Se "nao" ou o amigo não está na lista, adicionar ao final
    if (!inserted) {
        for (int i = 0; i < new_count; i++) {
            strcpy(temp_list[temp_count++], new_friends[i]);
        }
    }

    // Exibir a lista final
    for (int i = 0; i < temp_count; i++) {
        if (i > 0) printf(" ");
        printf("%s", temp_list[i]);
    }
    printf("\n");

    return 0;
}
