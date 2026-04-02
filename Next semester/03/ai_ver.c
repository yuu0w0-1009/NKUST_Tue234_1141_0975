#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 根據題目規格定義常數 [cite: 32, 35]
#define MAX_MEMBERS 100
#define NAME_SIZE 10
#define PHONE_SIZE 10
#define ADDR_SIZE 50

// 使用結構體封裝會員資料，提高可讀性 
typedef struct {
    int id;
    char name[NAME_SIZE + 1];
    char phone[PHONE_SIZE + 1];
    char address[ADDR_SIZE + 1];
} Member;

Member member_list[MAX_MEMBERS];
int current_count = 0;

// 輔助函式：尋找會員在陣列中的索引位置，找不到回傳 -1
int find_member_index(int id) {
    for (int i = 0; i < current_count; i++) {
        if (member_list[i].id == id) {
            return i;
        }
    }
    return -1;
}

// 輔助函式：依照 ID 由小到大排序 (Case 5 要求) 
void sort_members() {
    for (int i = 0; i < current_count - 1; i++) {
        for (int j = 0; j < current_count - i - 1; j++) {
            if (member_list[j].id > member_list[j + 1].id) {
                Member temp = member_list[j];
                member_list[j] = member_list[j + 1];
                member_list[j + 1] = temp;
            }
        }
    }
}

void manage_module() {
    int func_code;
    printf("Use member function\n"); // 進入模組提示 [cite: 13, 16]

    // 持續輸入功能代號，若非 1~5 則退出 [cite: 19, 27]
    while (scanf("%d", &func_code) == 1) {
        if (func_code < 1 || func_code > 5) break;

        int target_id, idx;
        switch (func_code) {
            case 1: // 新增會員 [cite: 20]
                scanf("%d", &target_id);
                if (find_member_index(target_id) != -1) {
                    char trash[200]; fgets(trash, 200, stdin); // 清掉該行剩餘輸入
                    printf("ID duplicated\n");
                } else {
                    member_list[current_count].id = target_id;
                    scanf("%s %s %s", member_list[current_count].name, 
                                      member_list[current_count].phone, 
                                      member_list[current_count].address);
                    current_count++;
                    printf("Creation successful\n");
                }
                break;

            case 2: // 修改會員 [cite: 22]
                scanf("%d", &target_id);
                idx = find_member_index(target_id);
                int field;
                char newData[ADDR_SIZE + 1];
                scanf("%d %s", &field, newData);
                
                if (idx == -1) {
                    printf("No such ID\n");
                } else {
                    if (field == 1) strcpy(member_list[idx].name, newData);
                    else if (field == 2) strcpy(member_list[idx].phone, newData);
                    else if (field == 3) strcpy(member_list[idx].address, newData);
                    printf("%d %s %s %s\n", member_list[idx].id, member_list[idx].name, 
                           member_list[idx].phone, member_list[idx].address);
                }
                break;

            case 3: // 刪除會員 [cite: 23]
                scanf("%d", &target_id);
                idx = find_member_index(target_id);
                if (idx == -1) {
                    printf("No such ID\n");
                } else {
                    // 將最後一筆移到被刪除的位置，並減少計數
                    member_list[idx] = member_list[current_count - 1];
                    current_count--;
                    printf("Deletion successful\n");
                }
                break;

            case 4: // 查詢單筆 [cite: 24]
                scanf("%d", &target_id);
                idx = find_member_index(target_id);
                if (idx == -1) printf("No such ID\n");
                else printf("%d %s %s %s\n", member_list[idx].id, member_list[idx].name, 
                            member_list[idx].phone, member_list[idx].address);
                break;

            case 5: // 查詢所有會員 (需排序) 
                sort_members();
                for (int i = 0; i < current_count; i++) {
                    printf("%d %s %s %s\n", member_list[i].id, member_list[i].name, 
                           member_list[i].phone, member_list[i].address);
                }
                break;
        }
    }
    printf("Exit member function\n"); // 退出模組提示 [cite: 27]
}

int main() {
    int module_code;

    // 主迴圈：處理模組切換 [cite: 12, 16]
    while (scanf("%d", &module_code) == 1 && module_code != -1) {
        if (module_code == 1) {
            manage_module();
        } else {
            printf("No such command\n"); // 非 1 且非 -1 [cite: 16]
        }
    }

    printf("Goodbye\n"); // 程式結束提示 [cite: 16]
    return 0;
}