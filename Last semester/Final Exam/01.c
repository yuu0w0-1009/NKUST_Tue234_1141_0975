#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void print_binary_d(int n) {
    if (n > 1) {
        print_binary_d(n / 2);
    }
    printf("%d", n % 2);
}

void print_binary_i(float n) {
    if (n == 0) return;
    while (n > 0) {
        n *= 2;
        int bit = n;
        printf("%d", bit);
        n -= bit;
    }
}

int main(void) {
    float input;
    scanf("%f", &input);

    int input_d = input;
    input -= input_d;

    if (input_d == 0) printf("0");
    else print_binary_d(input_d);

    if (input > 0) {
        printf(".");
        print_binary_i(input);
    }

    printf("\n");
    system("pause");
    return 0;
}