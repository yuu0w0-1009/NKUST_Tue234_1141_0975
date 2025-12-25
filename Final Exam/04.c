#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

int main(void) {
    int a = 0, b = 0, c = 0, d = 0, want = 0;
    int ra = 0, rb = 0, rc = 0, rd = 0, get = 0;
    int total = 0, change = 0;
    int drink[6] = { 0,15,23,25,37,50 };
    while (1) {
        ra = 0;
        rb = 0;
        rc = 0;
        rd = 0;
        scanf("%d", &a);
        if (a == -1)break;
        scanf("%d %d %d %d", &b, &c, &d, &want);
        total = a * 50 + b * 10 + c * 5 + d * 1;
        if (total < drink[want])
            printf("get:NA,change:%d %d %d %d\n", a, b, c, d);
        else {
            get = want;
            change = total - drink[want];
            while (1) {
                if (change >= 50) { change -= 50; ra += 1; }
                else if (change >= 10) { change -= 10; rb += 1; }
                else if (change >= 5) { change -= 5; rc += 1; }
                else if (change >= 1) { change -= 1; rd += 1; }
                else if (change == 0)break;
            }
            printf("get:%d,change:%d %d %d %d\n", get, ra, rb, rc, rd);
        }
    }
    system("pause");
    return 0;
}