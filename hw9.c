#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int len = 0, x = 0, y = 0;
char input[100];
char odd_n[50];
char even_n[50];
int result = 0;

// 區分奇偶數, char
int distinguish(char a[100]) {
    int z = 0;
    len = strlen(a);
    if (len % 2 == 0)z = 1;

    for (x = 0 + z; x < len; x += 2) {
        odd_n[y] = a[x];
        y++;
    }
    odd_n[y] = '\0';
    y = 0;

    for (x = 1 - z; x < len; x += 2) {
        even_n[y] = a[x];
        y++;
    }
    even_n[y] = '\0';
    y = 0;

    // for (x = 0; x < len; x++) {
    //     printf("%c ",odd_n[x]);
    // }
    // printf("\n");
    // for (x = 0; x < len; x++) {
    //     printf("%c ",even_n[x]);
    // }
    // printf("\n");

    return 0;
}

// 計算奇偶數, char -> int
int calculate(char a[50], char b[50]) {
    int temp = 0, odd_num = 0, even_num = 0;

    len = strlen(a);
    temp = len - 1;
    for (x = 0; x < len; x++) {
        odd_num = odd_num + (a[x] - '0') * pow(10, temp);
        temp--;
    }

    len = strlen(b);
    temp = len - 1;
    for (x = 0; x < len; x++) {
        even_num = even_num + (b[x] - '0') * pow(10, temp);
        temp--;
    }

    result = odd_num - even_num;
    // printf("%d\n", odd_num);
    // printf("%d\n", even_num);
    // printf("%d\n", result);

    printf("%d-%d=%d\n", odd_num, even_num, result);

    return result;
}

int main(void) {
    while (1){
        scanf("%s", &input);
        if(input[0]=='-')break;

        //算第一次
        distinguish(input);
        result = calculate(odd_n, even_n);

        //if>10 繼續算
        while (1) {
            if (result < 10)break;
            sprintf(input, "%d", result);
            distinguish(input);
            result = calculate(odd_n, even_n);
        }
    }

    system("pause");
    return 0;
}