#include <stdio.h>

int main()
{
    int a, b;
    int f = 1;   // 判斷是否為第一次輸出
    int con = 0; // 是否為質數
    int sum = 0;
    scanf_s("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        if (i < 2)
        {
            con = 0; // 1 和負數不是質數
        }
        else
        {
            con = 1; // 假設是質數
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    con = 0; // 找到因數，不是質數
                    break;
                }
            }
        }

        if (con == 1)
        {
            if (f != 1)
            {
                printf("+");
            }
            printf("%d", i);
            f = 0;
            sum += i;
        }
    }
    printf("=%d", sum);
    return 0;
}