#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

int main(void){
    int all=0,s=0,a=0,b=0,c=0,avg=0;
    int num[5];

    scanf("%d%d%d%d%d",&num[0],&num[1],&num[2],&num[3],&num[4]);

    all = num[0]+num[1]+num[2]+num[3]+num[4];

    avg = all/5;

    for (int i = 0; i < 5; i++){
        if (num[i]<60)c++;
        else if((num[i]>=60) & (num[i]<80))b++;
        else if((num[i]>=80) & (num[i]<100))a++;
        else s++;
    }

    printf("S=%d",s);
    printf("\nA=%d",a);
    printf("\nB=%d",b);
    printf("\nC=%d",c);
    printf("\nAVG=%d",avg);

    system("pause");
}