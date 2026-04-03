#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define startDx 0
#define startDy 1

// 定義座標點結構
typedef struct {
    int id;           // 敵軍編號
    double x;
    double y;
    double rel_angle; // 偽角度
    double distance;  // 與戰車的距離平方
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

// 降冪排序函數
int compare_clockwise(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    
    // 先比角度
    if (p1->rel_angle > p2->rel_angle) return -1;
    if (p1->rel_angle < p2->rel_angle) return 1;
    
    // 角度相同時 比距離
    if (p1->distance < p2->distance) return -1;
    if (p1->distance > p2->distance) return 1;
    
    return 0;
}

int main() {
    int n;
    int first = 0;

    while((scanf("%d", &n) != EOF)){

        if(n == -1)
            return 1;

        Point center;
        Point last;
        double center_dx, center_dy;
        
        // 首次啟動方向向北(0,1)
        if(first==0){
            last.x = 0;
            last.y = 0;
            center.x = 0;
            center.y = 0;
            center_dx = startDx;
            center_dy = startDy;
        }
        // 儲存上一次座標
        else{
            last.x = center.x;
            last.y = center.y;
        }
        
        // 輸入起始點
        scanf("%lf %lf", &center.x, &center.y);
        
        // 不是第一次:計算方向向量
        if(first==0)first = 1;
        else{
            center_dx = center.x - last.x;
            center_dy = center.y - last.y;
        }

        // 計算起始方向偽角度
        double start_p_angle = pseudoangle(center_dx, center_dy);
        Point *points = (Point *)malloc(n * sizeof(Point));

        if (points == NULL) {
            printf("記憶體配置失敗！\n");
            return 1;
        }
        
        // n行讀資料
        double *serial = (double*) malloc(n * sizeof(int));
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
            serial[i] = rel;
        }

        // 進行排序
        qsort(points, n, sizeof(Point), compare_clockwise);

        for (int i = 0; i < n; i++) {
            printf("%d ", points[i].id);
            // printf("points = %f ",points[i].rel_angle);
            // printf("serial = %f ",serial[i]);
        }

        puts("");

        // 釋放記憶體
        free(points);
    }
    
    return 0;
}
