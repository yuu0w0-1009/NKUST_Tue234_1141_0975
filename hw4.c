#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num=0, guess=0,L=1 ,R=100;
    scanf("%d",&num);

    printf("1~100\n");

    while (1){
        guess=0;
        scanf("%d",&guess);
        if(guess==num){printf("PASS\n");break;}
        else if(guess>num)R=guess-1;
        else if(guess<num)L=guess+1;
        printf("%d~%d\n",L,R);
    }

    system("pause");
}