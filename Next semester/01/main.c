#ifdef _MSC_VER
    #define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int partition(int n, int m) {
    if (n == 0 || m == 1) return 1;
    if (n < 0 || m <= 0) return 0;
    if (m > n) return partition(n, n);
    return partition(n - m, m) + partition(n, m - 1);
}

int main() {
    int n;
    while ( (scanf("%d", &n) != EOF) && n != -1) {
        printf("%d\n", partition(n, n));
    }
}
