#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int mode, value, temp, temp2, x, y, z, start=1;

    while (start)
    {
        scanf("%d %d",&mode,&value);

        switch (mode)
        {
        case -1:
        start=0;
            break;
        case 1:
        temp = value;
        for (x = 0; x < value; x++){
            for (y = 0; y < temp; y++){
                printf("*");
            }
            printf("\n");
            temp--;
        }
            break;
        case 2:
        temp = 1;
        for (x = 0; x < value; x++){
            for (y = 0; y < temp; y++){
                printf("*");
            }
            printf("\n");
            temp++;
        }   
            break;
        case 3:
        temp = value;
        temp2 = 1;
        for (x = 0; x < value; x++){
            for (y = 0; y < temp-1; y++){
                printf(" ");
            }
            for (y = 0; y < temp2; y++){
                printf("*");
            }
            printf("\n");
            temp--;
            temp2++;
        }
            break;
        case 4:
        temp = value;
        temp2 = 1;
        for (x = 0; x < value; x++){
            for (y = 0; y < temp2-1; y++){
                printf(" ");
            }
            for (y = 0; y < temp; y++){
                printf("*");
            }
            printf("\n");
            temp--;
            temp2++;
        }
            break;
        default:
        for (x = 0; x < value; x++){
            printf("*");
        }
        printf("\n");
            break;
        }
    }

    system("pause");

    return 0;
}
