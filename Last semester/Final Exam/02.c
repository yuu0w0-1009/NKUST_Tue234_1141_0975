#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

int main(void) {
    int d1 = 0, d2 = 0, first_flag = 0, flag = 0, result = 0;
    scanf("%d %d", &d1, &d2);

    while (1) {
        if (d1 == d2 + 1)break;
        flag = 0;
        for (int i = 2; i <= d1 / 2; ++i)
            if (d1 % i == 0) { flag = 1; break; }

        if (flag == 0 && d1 > 1) {
            result = result + d1;
            if (first_flag == 1)printf("+%d", d1);
            else {first_flag++; printf("%d+", d1);}
        }
        d1++;
    }

    printf("=%d\n", result);
    system("pause");
    return 0;
}