#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// 比較函數，提供給 qsort 排序 uint32_t 使用
int compare_uint32(const void *a, const void *b) {
    uint32_t arg1 = *(const uint32_t *)a;
    uint32_t arg2 = *(const uint32_t *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

// 二分搜尋法，用於快速確認該 ID 是否存在於重複名單中
bool is_repeated(uint32_t target, uint32_t *arr, int size) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main() {
    // 平行陣列管理 600 卷資料
    uint32_t **sector_data = (uint32_t **)calloc(600, sizeof(uint32_t *));
    size_t *sector_counts = (size_t *)calloc(600, sizeof(size_t));
    size_t *sector_caps = (size_t *)calloc(600, sizeof(size_t));

    int c;
    uint32_t id;
    size_t total_items = 0;

    // 讀取資料：遇到 -1 或 EOF 即停止
    while (scanf("%d", &c) == 1 && c != -1) {
        // 讀取十六進位識別碼 (scanf 的 %x 會自動處理 0x 前綴)
        if (scanf("%x", &id) != 1) break;

        if (c >= 0 && c < 600) {
            // 動態翻倍增長，避免頻繁 realloc 導致 TLE
            if (sector_counts[c] == sector_caps[c]) {
                sector_caps[c] = (sector_caps[c] == 0) ? 8 : sector_caps[c] * 2;
                sector_data[c] = (uint32_t *)realloc(sector_data[c], sector_caps[c] * sizeof(uint32_t));
            }
            sector_data[c][sector_counts[c]++] = id;
            total_items++;
        }
    }

    // 步驟 1: 將所有讀取到的 ID 集中到一維陣列，方便找出重複項目
    uint32_t *all_ids = (uint32_t *)malloc(total_items * sizeof(uint32_t));
    size_t k = 0;
    for (int i = 0; i < 600; i++) {
        for (size_t j = 0; j < sector_counts[i]; j++) {
            all_ids[k++] = sector_data[i][j];
        }
    }

    // 步驟 2: 將所有 ID 排序 (O(N log N))
    qsort(all_ids, total_items, sizeof(uint32_t), compare_uint32);

    // 步驟 3: 掃描排序後的陣列，揪出所有重複樣本並存入獨立陣列
    uint32_t *repeated_ids = (uint32_t *)malloc(total_items * sizeof(uint32_t));
    int rep_count = 0;
    for (size_t i = 0; i < total_items; i++) {
        // 若當前 ID 與下一個 ID 相同，則為重複樣本
        if (i < total_items - 1 && all_ids[i] == all_ids[i+1]) {
            // 確保同一個重複樣本只被加入 repeated_ids 一次
            if (rep_count == 0 || repeated_ids[rep_count - 1] != all_ids[i]) {
                repeated_ids[rep_count++] = all_ids[i];
            }
        }
    }
    // 釋放尋找重複項目的暫存陣列
    free(all_ids);

    // 步驟 4: 依照卷號由 0 至 599 輸出結果
    for (int i = 0; i < 600; i++) {
        int valid_count = 0;
        
        // 第一階段：計算該卷扣除重複項目後的「有效件數」
        for (size_t j = 0; j < sector_counts[i]; j++) {
            if (!is_repeated(sector_data[i][j], repeated_ids, rep_count)) {
                valid_count++;
            }
        }

        // 第二階段：若有效件數 > 0，則印出該卷資料
        if (valid_count > 0) {
            printf("%d(%d):", i, valid_count);
            for (size_t j = 0; j < sector_counts[i]; j++) {
                if (!is_repeated(sector_data[i][j], repeated_ids, rep_count)) {
                    printf(" 0x%08X", sector_data[i][j]);
                }
            }
            printf("\n");
        }
    }

    // 步驟 5: 輸出重複樣本報告
    printf("Repeated IDs:");
    for (int i = 0; i < rep_count; i++) {
        printf(" 0x%08X", repeated_ids[i]);
    }
    printf("\n");

    // 步驟 6: 妥善釋放所有動態配置的記憶體
    for (int i = 0; i < 600; i++) {
        if (sector_data[i] != NULL) {
            free(sector_data[i]);
        }
    }
    free(sector_data);
    free(sector_counts);
    free(sector_caps);
    free(repeated_ids);

    return 0;
}