#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        int n1, d1, n2, d2, num, den;
        char op;
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
        if (op == '+') {
            num = n1 * d2 + n2 * d1;
            den = d1 * d2;
        } else if (op == '-') {
            num = n1 * d2 - n2 * d1;
            den = d1 * d2;
        } else if (op == '*') {
            num = n1 * n2;
            den = d1 * d2;
        } else if (op == '/') {
            num = n1 * d2;
            den = n2 * d1;
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int divisor = mdc(abs(num), abs(den));
        int num_simplificado = num / divisor;
        int den_simplificado = den / divisor;
        printf("%d/%d = %d/%d\n", num, den, num_simplificado, den_simplificado);
    }
    
    return 0;
}
