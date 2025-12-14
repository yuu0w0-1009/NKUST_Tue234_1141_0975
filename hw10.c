#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

//A1 = 1
//A(n) = 2[A(n-1)] + 1
//A(n) = 2^n - 1

//1~N-1 to B
//N to C
//1~N to C

int tower[3][10] = {
    {0},    //A
    {0},    //B
    {0},    //C
};

void hanoi(int n, char from, char to, char temp) {
    if (n == 1) {
        printf("Move sheet from %c to %c\n", from, to);
    }
    else {
        hanoi(n - 1, from, temp, to);
        hanoi(1, from, to, temp);
        hanoi(n - 1, temp, to, from);
    }
}

int main() {
    int n;
    printf("請輸入盤數：");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        tower[0][i] = i + 1;
        printf("%d\n", tower[0][i]);
    }

    hanoi(n, 'A', 'B', 'C');
    system("pause");
    return 0;
}
