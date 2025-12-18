#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

int main(void){
    int d1 = 0, d2 = 0, result = 0, point = 0;
    srand(time(NULL));

    d1 = 1 + (rand() % 6);
    d2 = 1 + (rand() % 6);
    result = d1 + d2;

    printf("Player rolled %d + %d = %d\n",d1,d2,result);

    if((result == 7)||(result == 11))printf("Player wins\n");
    else if((result == 2)||(result == 3)||(result == 12))printf("Player loses\n");
    else{
        point = result;
        while (1){
            d1 = 1 + (rand() % 6);
            d2 = 1 + (rand() % 6);
            result = d1 + d2;
            printf("Player rolled %d + %d = %d\n",d1,d2,result);
            if(result == 7){printf("Player loses\n");break;}
            else if(result == point){printf("Player wins\n");break;}
        } 
    }
    system("pause");
    return 0;
}