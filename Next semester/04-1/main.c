#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定義座標點結構
typedef struct {
    double x;
    double y;
    double rel_angle; 
} Point;

// 偽角度演算法
double pseudoangle(double dx, double dy) {
    if (dx == 0.0 && dy == 0.0) return 0.0; 
    
    double p = dx / (fabs(dx) + fabs(dy));
    if (dy < 0.0) {
        return p - 1.0;
    } else {
        return 1.0 - p;
    }
}

// 降冪排序函數 (確保順時針)
int compare_clockwise(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    
    if (p1->rel_angle > p2->rel_angle) return -1;
    if (p1->rel_angle < p2->rel_angle) return 1;
    return 0;
}

int main() {
    int n;
    
    // 1. 第一行：輸入有幾組待測資料 (n)
    if (scanf("%d", &n) != 1) return 1;

    // 2. 第二行：輸入起始點 (x y)
    Point center;
    scanf("%lf %lf", &center.x, &center.y);

    // 3. 第三行：輸入起始向量 (dx dy)
    double start_dx, start_dy;
    scanf("%lf %lf", &start_dx, &start_dy);
    
    // 計算起始方向的基準偽角度
    double start_p_angle = pseudoangle(start_dx, start_dy);

    // 動態配置記憶體，根據輸入的 n 建立對應大小的陣列
    Point *points = (Point *)malloc(n * sizeof(Point));
    if (points == NULL) {
        printf("記憶體配置失敗！\n");
        return 1;
    }

    // 4. 之後的 n 行：讀取每一組待測資料 (x y)
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
        
        // 讀取後直接計算相對偏移量
        double dx = points[i].x - center.x;
        double dy = points[i].y - center.y;
        
        double p_angle = pseudoangle(dx, dy);
        double rel = p_angle - start_p_angle;
        
        // 環形校正
        if (rel > 0) {
            rel -= 4.0;
        }
        points[i].rel_angle = rel;
    }

    // 使用 qsort 進行排序
    qsort(points, n, sizeof(Point), compare_clockwise);

    // 輸出排序後的結果
    printf("\n--- 順時針排序結果 ---\n");
    for (int i = 0; i < n; i++) {
        // 印出座標，並附上計算出的相對偽角度供驗證
        printf("(%.1f, %.1f) | 相對角度值: %6.3f\n", 
               points[i].x, points[i].y, points[i].rel_angle);
    }

    // 釋放動態配置的記憶體 (養成好習慣)
    free(points);

    return 0;
}