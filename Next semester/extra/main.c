#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[] = "data.txt";

    // ----------------------------
    // 步驟一：寫入檔案 (Write)
    // ----------------------------
    
    // 1. 以寫入模式 ("w") 開啟檔案
    fp = fopen(filename, "w+");
    if (fp == NULL) {
        printf("無法開啟檔案進行寫入！\n");
        return 1;
    }

    // 2. 循序寫入資料
    // fprintf(fp, "這是第一行：C語言檔案處理\n");
    // fputs("這是第二行：循序存取範例\n", fp);
    fprintf(fp, "test:%d, %d, %d \n", 1, 2, 3);
    fputs("second", fp);

    printf("write done %s\n", filename);

    // ----------------------------
    // 步驟二：讀取檔案 (Read)
    // ----------------------------
    

    // 1. 循序讀取資料 (使用 fgets 逐行讀取直到檔尾)
    char buffer[256];
    printf("--- start to read ---\n");
    
    // 2. 當 fgets 不回傳 NULL 時，代表還沒讀到檔尾 (EOF)
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    
    printf("--- read end ---\n");

    // 3. 關閉檔案
    fclose(fp);

    return 0;
}