#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
int main(void){
    int a = 0, b = 0;
    scanf("%d %d",&a,&b);
    printf("a plus b equals %d\n",a+b);
    printf("a minus b equals %d\n",a-b);
    printf("a times b equals %d\n",a*b);
    printf("a divided by b equals %d\n",a/b);
    system("pause");
    return 0;
}