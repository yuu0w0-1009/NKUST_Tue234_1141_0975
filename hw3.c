#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int num = 0,start = 1;
int r[8]={0};
// x = p * q + r

void bin(void){
    int i = 0;

    while (1){
        r[i++] = num % 2;
        num = num / 2;
        if(num==0)break;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d",r[j]);
    }

    printf("\n");
    return;
}

int main(void) {
    while (start){
        scanf("%d",&num);
        if (num >= 0)bin();
        else start=0;
    }
    system("pause");
}