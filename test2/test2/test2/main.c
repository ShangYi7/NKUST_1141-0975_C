#include <stdio.h>

int main()
{
    int a, b, sum = 0;
    int count = 0;
    int first = 1; //判斷是否為第一個輸出
    scanf_s("%d %d", &a, &b);
    // 質數判斷
    for (int i = a; i <= b; i++)
    {
        if (i < 2){
            continue;
        }

        count = 1;
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