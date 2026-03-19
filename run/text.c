#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); }

int main(){
    int N;
    int data[100]={0};

    while ( (scanf("%d",&N) != EOF) && N != -1) {
        for (int i = 0; i < N; i++){
            scanf("%d",&data[i]);
        }

        qsort(data, N, sizeof(int), compare);

        for (int i = 0; i < N; i++){
            printf("%d ",data[i]);
        }
        puts("");
    }
    system("pause");
    return 0;
}