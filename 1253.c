#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);  
    while (N--) {
        char encoded[51]; 
        int k;
        scanf("%s", encoded);
        scanf("%d", &k);   
        int len = strlen(encoded);  
        char decoded[len + 1];     
        for (int i = 0; i < len; i++) {
            char ch = encoded[i];
            decoded[i] = ((ch - 'A' - k + 26) % 26) + 'A';  
        }
        decoded[len] = '\0';  
        printf("%s\n", decoded);
    }
    return 0;
}
