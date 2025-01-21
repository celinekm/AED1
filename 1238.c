#include <stdio.h>
#include <string.h>

int main() {
    int N;  
    scanf("%d", &N);  
    for (int i = 0; i < N; i++) {
        char str1[51], str2[51];  
        scanf("%s %s", str1, str2);     
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int max_len = (len1 > len2) ? len1 : len2;  
        
        char result[101]; 
        int idx = 0;  
        for (int j = 0; j < max_len; j++) {
            if (j < len1) {
                result[idx++] = str1[j];  
            }
            if (j < len2) {
                result[idx++] = str2[j];  
            }
        }
        
        result[idx] = '\0';  
        printf("%s\n", result);
    }
    return 0;
}
