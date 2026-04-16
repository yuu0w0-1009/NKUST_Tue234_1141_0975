#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max_val(int a, int b) {
    return (a > b) ? a : b;
}

int main(){
    int N, O;
    int ASCII = 65; //A = 65
    // printf("%c\n",ASCII);

    while ( (scanf("%d %d",&O,&N) != EOF)) {
        if((N <= 0) || (O < 1) || (O > 26))
            break;
        // printf("O=%d N=%d\n",O,N);

        int size = 2 * N - 1;

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                // printf("%d",abs(j - N + 1));
                // printf("%d",abs(i - N + 1));
                int num = max_val(abs(i - N + 1),abs(j - N + 1));
                printf("%c",ASCII + num % O);
            }
            printf("\n");
        }
    }
    
    return 0;
}