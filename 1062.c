#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        while (1) {
            int target[1000];
            int stack[1000];
            int top = -1, current = 1, i;

            scanf("%d", &target[0]);
            if (target[0] == 0) {
                printf("\n");
                break;
            }

            for (i = 1; i < N; i++) {
                scanf("%d", &target[i]);
            }

            for (i = 0; i < N; i++) {
                while (current <= target[i]) {
                    stack[++top] = current++;
                }
                
                if (stack[top] == target[i]) {
                    top--;
                } else {
                    printf("No\n");
                    goto next_case;
                }
            }
            printf("Yes\n");
            next_case:;
        }
    }
    return 0;
}
