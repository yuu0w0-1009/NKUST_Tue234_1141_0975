#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int mode;
    int num1, num2;

    while (1) {
        scanf("%d", &mode);

		if (mode == -1) break;

        scanf("%d %d", &num1, &num2);

        if (mode == 1) printf("%d ", gcd(num1, num2));
		else if(mode == 2)printf("%d ", lcm(num1, num2));
		printf("\n");
    }
	system("pause");
    return 0;
}