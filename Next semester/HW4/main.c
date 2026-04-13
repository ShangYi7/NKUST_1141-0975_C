#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int cx, cy; // 戰車座標
    int ex[6], ey[6]; // 敵人座標

    int px = 0, py = 0; // 上一個點位
    int has_prev = 0;

    int hx = 0, hy = 1; // 初始朝向：正北

    while (scanf("%d", &n) == 1) {
        if (n == -1) {
            break;
        }
        if (n < 1 || n > 6) {
            continue;
        }

        if (scanf("%d %d", &cx, &cy) != 2) {
            return 0;
        }

        // 抵達新點位後，車體朝向改成位移向量
        if (has_prev) {
            int vx = cx - px;
            int vy = cy - py;
            if (vx != 0 || vy != 0) {
                hx = vx;
                hy = vy;
            }
        }

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &ex[i], &ey[i]);
        }

        double angle[6];
        long long dist2[6];
        int order[6];

        for (int i = 0; i < n; i++) {
            int tx = ex[i] - cx;
            int ty = ey[i] - cy;
            double cross = (double)hx * ty - (double)hy * tx;
            double dot = (double)hx * tx + (double)hy * ty;

            // 順時針角度（0 到 2*pi）
            angle[i] = atan2(-cross, dot);
            if (angle[i] < 0) {
                angle[i] += 2.0 * acos(-1.0);
            }

            dist2[i] = (long long)tx * tx + (long long)ty * ty;
            order[i] = i;
        }

        // 最簡單排序：先角度，再距離
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = order[i];
                int b = order[j];
                if (angle[a] > angle[b] ||
                    (angle[a] == angle[b] && dist2[a] > dist2[b])) {
                    int tmp = order[i];
                    order[i] = order[j];
                    order[j] = tmp;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", order[i]);
        }
        printf("\n");

        px = cx;
        py = cy;
        has_prev = 1;
    }

    return 0;
}