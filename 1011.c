#include <stdio.h>

int main() {
    double R;  
    scanf("%lf", &R);  
    double volume = (4.0 / 3) * 3.14159 * (R * R * R);
    printf("VOLUME = %.3lf\n", volume);
    return 0;
}
