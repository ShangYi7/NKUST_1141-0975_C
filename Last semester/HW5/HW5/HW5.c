#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b;
    int sum = 0;
    int start, end;

    // 讀取使用者輸入的兩個正整數
    scanf("%d %d", &a, &b);

    // 確保 start 是較小的數，end 是較大的數
    if (a < b) {
        start = a;
        end = b;
    }
    else {
        start = b;
        end = a;
    }

    // 如果 start 是偶數，則加 1 使其成為奇數
    if (start % 2 == 0) {
        start++;
    }

    // 計算並顯示奇數總和
    for (int i = start; i <= end; i += 2) {
        sum += i;

        // 顯示計算過程
        printf("%d", i);

        // 如果不是最後一個數，則顯示 +
        if (i + 2 <= end) {
            printf("+");
        }
    }

    // 顯示等號和總和
    printf("=%d\n", sum);

    return 0;
}