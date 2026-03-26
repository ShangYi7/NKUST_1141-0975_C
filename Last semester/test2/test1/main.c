#include <stdio.h>

int main()
{
    float data = 0;
    int a = 0;   // 小數點前
    float b = 0; // 小數點後
    int c = 1;   // 進位
    int ans = 0; // 答案
    scanf_s("%f", &data);
    a = data;     // 小數點前
    b = data - a; // 小數點後
    // printf("a=%d b=%f\n", a, b);

    // 小數點前轉二進位
    while (a != 0)
    {
        ans = ans + (a % 2) * c;
        c = c * 10;
        a = a / 2;
    }
    printf("%d", ans);
    // 小數點後轉二進位
    if (b > 0)
    {
        printf(".");
        while (b != 0)
        {
            b = b * 2;
            ans = b; // 取整數部分
            printf("%d", ans);
            if (ans == 1)
            {
                b = b - 1; // 去掉整數部分
            }
        }
    }
    return 0;
}