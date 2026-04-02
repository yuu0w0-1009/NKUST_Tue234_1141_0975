# HW04：戰車火控系統
[cite_start]**課程：** 114-2 計算機程式設計 [cite: 1, 2]  
[cite_start]**截止日期：** 2026/04/15 12:00 [cite: 4]

## 題目說明
[cite_start]戰車會在地圖上多個預定點位之間移動，每抵達一個點位，偵察機會回傳周遭敵軍的絕對座標 [cite: 7][cite_start]。受限於機載火控系統的設計，此戰車的砲塔僅能**單向順時針旋轉**來鎖定目標 [cite: 7][cite_start]。戰車抵達新點位後，會以當下的車頭朝向為基準，進行一輪順時針掃蕩，依序清空該區所有目標 [cite: 7]。

### [cite_start]開火順序邏輯 [cite: 8, 16]
1.  [cite_start]**旋轉角度：** 依照目標相對於「此時車頭朝向」的**順時針旋轉角度**，由小到大排序 ($0^{\circ} \le \theta < 360^{\circ}$) [cite: 9, 17]。
2.  [cite_start]**優先距離：** 若多個目標處於相同的旋轉角度上，則優先攻擊**距離最近**（歐式距離 Euclidean Distance）的目標 [cite: 10, 18]。

---

## 實作規範
1.  [cite_start]**環境與數值：** 程式於 Linux 環境編譯。座標 ($X, Y$) 為正整數，範圍為 $1 \le X, Y \le 500$ [cite: 12]。
2.  [cite_start]**輸入與結束：** * 第一行為敵軍數量 $N$ ($1 \le N \le 6$) [cite: 13]。
    * [cite_start]若讀到 $N = -1$ 則程式結束 [cite: 13]。
3.  [cite_start]**座標與編號：** * 讀取 $N$ 後，下一行為戰車座標 $C_x, C_y$ [cite: 14]。
    * [cite_start]隨後為 $N$ 行敵軍座標 $E_x, E_y$ [cite: 14]。
    * [cite_start]敵軍編號從 **0** 開始依輸入順序遞增 [cite: 14]。
    * [cite_start]測資保證座標不重疊 [cite: 14]。
4.  [cite_start]**戰車朝向：** * **初始點位：** 預設車頭朝向正北，方向向量為 $(0, 1)$ [cite: 15]。
    * [cite_start]**後續點位：** 朝向為位移向量 $\vec{V} = (C_x - P_x, C_y - P_y)$，其中 $(P_x, P_y)$ 為上一個點位的座標 [cite: 15]。
5.  [cite_start]**輸出格式：** 於一行內輸出排序後的敵軍編號，編號間以單一空白字元分隔 [cite: 19]。

---

## 範例測試

### [cite_start]範例輸入 [cite: 24-27, 31-38]
```text
4
50 50
56 8
1 52
93 12
39 75
2
3 70
44 81
80 75
-1
```

### [cite_start]範例輸出 [cite: 30, 53]
```text
2 0 1 3
0 1
```

### [cite_start]範例說明 [cite: 39]
* [cite_start]**初始回合：** 戰車位於 (50, 50)，朝向正北 (0, 1)。敵人 2 的旋轉角最小 ($131.5^{\circ}$)，依序為 2 → 0 → 1 → 3 [cite: 41-47]。
* [cite_start]**第二回合：** 戰車移至 (3, 70)，朝向向量為 $(3-50, 70-50) = (-47, 20)$。排序結果為 0 → 1 [cite: 49-53]。

---

## [cite_start]提示與參考 [cite: 60]

### [cite_start]解題思路 [cite: 61]
1.  [cite_start]**使用角度：** 利用 `atan2(y, x)` 計算徑度，平移轉換後排序 [cite: 62]。
2.  [cite_start]**使用偏角度 (Pseudo-angle)：** 利用座標差值計算具單調性的數值替代三角函數 [cite: 63]。
3.  [cite_start]**使用向量法：** 利用**向量外積 (Cross Product)** 判斷旋轉方向，無需浮點數運算 [cite: 64]。

### 參考連結
* [cite_start][atan2 C++ Reference](https://cplusplus.com/reference/cmath/atan2/) [cite: 74, 75]
* [cite_start][Fastest way to sort vectors by angle (Stack Overflow)](https://stackoverflow.com/questions/16542042/) [cite: 76, 78]
* [cite_start][Geometry Basics & Sorting (CP-Algorithms)](https://cp-algorithms.com/geometry/basic-geometry.html) [cite: 79]
* [cite_start][Cross product (Wikipedia)](https://en.wikipedia.org/wiki/Cross_product) [cite: 80, 81]

---