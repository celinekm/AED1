#include <stdio.h>
 
int main() {
    int h , v;
    float d , gasto;
    scanf("%d", &h);
    scanf("%d", &v);
    
    d = v * h;
    
    gasto = d / 12;
    
    printf("%.3f\n" , gasto);
    
    return 0;
}
