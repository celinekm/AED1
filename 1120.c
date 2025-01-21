#include <stdio.h>
#include <string.h>

int main() {
    int D;
    char N[101];  
    while (1) {
        scanf("%d %s", &D, N);
        if (D == 0 && N[0] == '0' && N[1] == '\0') {
            break;
        }
        char result[101];  
        int j = 0; 
        for (int i = 0; N[i] != '\0'; i++) {
            if (N[i] != D + '0') { 
                result[j++] = N[i];
            }
        }
        result[j] = '\0';  
        int start = 0;
        while (result[start] == '0' && result[start] != '\0') {
            start++;
        }
        if (result[start] == '\0') {
            printf("0\n");
        } else {
            printf("%s\n", result + start);
        }
    }
    return 0;
}
