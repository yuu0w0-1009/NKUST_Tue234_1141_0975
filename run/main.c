#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double rel_angle; // 儲存與起始方向的「相對偽角度」
} Point;

// 偽角度演算法 (不變)
// 回傳範圍 [-2, 2]，逆時針遞增
double pseudoangle(double dx, double dy) {
    if (dx == 0.0 && dy == 0.0) {
        return 0.0; 
    }
    
    double p = dx / (fabs(dx) + fabs(dy));
    
    if (dy < 0.0) {
        return p - 1.0;
    } else {
        return 1.0 - p;
    }
}

// 降冪排序函數 (不變)
int compare_clockwise(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    
    if (p1->rel_angle > p2->rel_angle) return -1;
    if (p1->rel_angle < p2->rel_angle) return 1;
    return 0;
}

int main() {
    Point center_point = {50, 50}; 
    Point center_vector = {0,1};
    
    // 計算起始方向的基準偽角度
    double start_p_angle = pseudoangle(center_vector.x, center_vector.y);
    
    int num_points = 4;
    Point points[] = {
        {56, 8, 0},
        {1, 52, 0},
        {93, 12, 0},
        {39, 75, 0}
    };

    printf("中心點: (%.1f, %.1f)\n", center_point.x, center_point.y);
    printf("起始向量: dx=%.1f, dy=%.1f (基準偽角度: %.3f)\n\n", center_vector.x, center_vector.y, start_p_angle);

    // 1. 計算每個點的「相對」偽角度
    for (int i = 0; i < num_points; i++) {
        double dx = points[i].x - center_point.x;
        double dy = points[i].y - center_point.y;
        
        // 算出該點的絕對偽角度
        double p_angle = pseudoangle(dx, dy);
        
        // 計算與起始方向的相對差值
        double rel = p_angle - start_p_angle;
        
        // 【核心邏輯】環形校正
        // 如果 rel > 0，代表該點在起始點的逆時針方向 (也就是順時針的最後面)
        // 偽角度的完整一圈長度是 4.0，所以減去 4.0 把它推到數列的尾端
        if (rel > 0) {
            rel -= 4.0;
        }
        
        // 儲存結果 (最終數值會落在 [-4, 0] 之間)
        points[i].rel_angle = rel;
    }

    // 2. 進行排序
    qsort(points, num_points, sizeof(Point), compare_clockwise);

    // 3. 印出結果
    printf("--- 從自訂方向開始，順時針排序後 ---\n");
    for (int i = 0; i < num_points; i++) {
        printf("順位 %d -> 座標: (%5.1f, %5.1f) | 相對角度值: %6.3f\n", 
               i+1, points[i].x, points[i].y, points[i].rel_angle);
    }

    return 0;
}