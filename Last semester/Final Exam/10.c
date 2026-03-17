#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

void hanoi(int n, char from, char temp, char to) {
    if (n == 1)
        printf("move %d from %c to %c\n", n, from, to);
    else {
        hanoi(n - 1, from, to, temp);
        printf("move %d from %c to %c\n", n, from, to);
        hanoi(n - 1, temp, from, to);
    }
}

int main() {
    int num;
    while (1){
        scanf("%d", &num);
        if(num==-1)break;
        hanoi(num, 'A', 'B', 'C');
    }
    system("pause");
    return 0;
}
