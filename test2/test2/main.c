#include <stdio.h>

int main()
{
    int a, b, sum = 0;
    int count = 1; //1 == 質數, 0 == 非質數
    int first = 1; //判斷是否為第一個輸出
    scanf_s("%d %d", &a, &b);
    // 質數判斷
    for (int i = a; i <= b; i++)
    {
        // 0 跟 1 不是質數
        if (i < 2){
            continue;
        }

        for (int j = 2; j < i; j++)
        {
            if (i % j == 0) //非質數
            {
                count = 0;
                break;
            }
        }

        if (count == 1)
        {
            if (first==0)
                printf("+");
            printf("%d", i);
            sum += i;
            first = 0;
        }
    }
    printf("=%d\n", sum);
    return 0;
}