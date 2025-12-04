#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, i, temp, sum = 0, last_odd = 0;
    
    scanf("%d %d", &a, &b);

    //確保 a 永遠是比較小
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    //逆向迴圈定位終點
    for (i = b; i >= a; i--) {
        if (i % 2 != 0) {
            last_odd = i;
            break;
        }
    }

    //計算與列印迴圈
    for (i = a; i <= b; i++) {
        if (i % 2 != 0) {
            printf("%d", i);
            sum += i;
            if (i < last_odd) {
                printf("+");
            }
        }
    }

    printf("=%d\n", sum);

    system("pause");

    return 0;
}
