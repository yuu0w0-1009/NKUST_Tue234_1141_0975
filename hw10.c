#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

//A1 = 1
//A(n) = 2[A(n-1)] + 1
//A(n) = 2^n - 1

//1~N-1 to B
//N to C
//1~N to C

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        printf("move %d from %c to %c\n", n, A, C);
    }
    else {
        hanoi(n - 1, A, C, B);
        printf("move %d from %c to %c\n", n, A, C);
        hanoi(n - 1, B, A, C);
    }
}

int main() {
    int n;
    printf("請輸入盤數：");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');
    system("pause");
    return 0;
}
