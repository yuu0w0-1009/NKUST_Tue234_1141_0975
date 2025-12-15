#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

int main(void) {
    int x = 0;
    int mode = 0; // 1 = 0, 2 = 1 , 3 = 1.1
    int input_i = 0;
    float input = 0, input_d = 0;
    int result[50] = { 0 };
    scanf("%f", &input);

    input_i = (int)input;
    input_d = input - input_i;

    if (input == 0)mode = 1;
    else if (input_d == 0)mode = 2;
    else mode = 3;

    switch (mode){
    case 1:
        printf("0");
        break;
    case 2:
        while (1) {
            if (input_i == 0)break;
            result[x++] = input_i % 2;
            input_i /= 2;
        }
        break;
    case 3:
        while (1) {
            if (input_d == 0)break;
            input_d *= 2;
            if (input_d >= 1.0) {
                result[x++] = 1;
                input_d -= 1.0;
            }
            else 
                result[x++] = 0;
        }
        result[x++] = 999;
        while (1) {
            if (input < 1)result[x++] = 0;
            if (input_i == 0)break;
            result[x++] = input_i % 2;
            input_i /= 2;
        }
        break;
    default:
        break;
    }

    for (int i = x - 1; i >= 0; i--) {
        if (result[i] == 999)printf(".");
        else printf("%1d", result[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}