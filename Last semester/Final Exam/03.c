#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

int main(void) {
    int mode = 0, data = 0, temp1 = 0, temp2 = 0;

    while (1) {
        scanf("%d", &mode);
        if (mode < 0)break;
        scanf("%d", &data);
        switch (mode) {
        case 1:
            temp1 = data;
            for (int x = 0; x < data; x++) {
                for (int i = 0; i < temp1; i++) {
                    printf("*");
                }
                temp1--;
                printf("\n");
            }
            break;
        case 2:
            temp1 = 1;
            for (int x = 0; x < data; x++) {
                for (int i = 0; i < temp1; i++) {
                    printf("*");
                }
                temp1++;
                printf("\n");
            }
            break;
        case 3:
            temp1 = data;
            temp2 = 1;
            for (int x = 0; x < data; x++) {
                for (int i = 0; i < temp1 - 1; i++) {
                    printf(" ");
                }
                for (int i = 0; i < temp2; i++) {
                    printf("*");
                }
                temp1--;
                temp2++;
                printf("\n");
            }
            break;
        case 4:
            temp1 = data;
            temp2 = 1;
            for (int x = 0; x < data; x++) {
                for (int i = 0; i < temp2 - 1; i++) {
                    printf(" ");
                }
                for (int i = 0; i < temp1; i++) {
                    printf("*");
                }
                temp1--;
                temp2++;
                printf("\n");
            }
            break;
        default:
            temp1 = data;
            temp2 = 1;
            for (int x = 0; x < data; x++) {
                for (int i = 0; i < temp1 - 1; i++) {
                    printf(" ");
                }
                for (int i = 0; i < temp2; i++) {
                    printf("* ");
                }
                temp1--;
                temp2++;
                printf("\n");
            }
            temp1 = data - 1;
            temp2 = 1;
            for (int x = 0; x < data - 1; x++) {
                for (int i = 0; i < temp2; i++) {
                    printf(" ");
                }
                for (int i = 0; i < temp1; i++) {
                    printf("* ");
                }
                temp1--;
                temp2++;
                printf("\n");
            }
            break;
        }
    }
    system("pause");
    return 0;
}