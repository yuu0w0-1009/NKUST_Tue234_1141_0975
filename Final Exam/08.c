#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

int fib(int n){
    int result = 0;
    if((n == 0)||(n == 1))result = n;
    else{
        result = fib(n-1)+fib(n-2);
    }
    return result;
}

int main(void){
    int num = 0, result = 0;
    scanf("%d",num);

    result = fib(num);
    printf("F(%d)=%d",num,result);
    
    system("pause");
    return 0;
}