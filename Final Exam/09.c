#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

int main(void){
    int guess = 0, goal = 0, max = 100, min = 0;
    scanf("%d",goal);
    while (1){
        scanf("%d",guess);
        if(guess == goal){printf("PASS");break;}
        else{
            if(guess > goal)max = guess;
            else min = guess;
            printf("%d~%d",min,max);
        }
    }
    system("pause");
    return 0;
}