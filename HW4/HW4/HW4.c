#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int x =0; 
	int count_min = 1, count_max = 100;
	int intput;
    scanf("%d", &x);
	printf("1~100\n");
    while (1) {
        scanf("%d", &intput);

        // 檢查是否猜中
        if (intput == x) {
            printf("PASS\n");
            break;
        }

        // 縮小範圍並顯示新範圍
        if (intput < x) {
            count_min = intput + 1;
        }
        else {
            count_max = intput - 1;
        }

        printf("%d~%d\n", count_min, count_max);
    }

    return 0;
}
