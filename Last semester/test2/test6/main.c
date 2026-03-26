#include <stdio.h>
#include <string.h>
char input[100];
int num, P = 0, Q = 0;
int sun;
int main()
{
    while (1)
    {
        // scanf_s == 讀取輸入字串
        // scanf_s(格式, 變數, 變數大小);
        scanf_s("%s", input, 100);
        if (input[0] == '-')
        {
            break;
        }
        // Division
        // strlen() == 計算字串長度
        num = strlen(input);
        P = 0;
        Q = 0;
        if (num % 2 == 0) // 偶數
        {

            for (int i = 0; i < num; i += 2)
            {
                Q = Q * 10 + (input[i] - '0');
            }
            for (int i = 1; i < num; i += 2)
            {
                P = P * 10 + (input[i] - '0');
            }
        }
        else // 奇數
        {
            for (int i = 0; i < num; i += 2)
            {
                P = P * 10 + (input[i] - '0');
            }
            for (int i = 1; i < num; i += 2)
            {
                Q = Q * 10 + (input[i] - '0');
            }
        }

        // Subtraction
        sun = P - Q;
        printf("%d-%d=%d\n", P, Q, sun);
        while (sun >= 10)
        {
            // sprintf_s == 把結果存在陣列中
            // sprintf_s(字串陣列, 陣列大小, 格式, 變數);
            sprintf_s(input, 100, "%d", sun);
            num = strlen(input);
            P = 0;
            Q = 0;
            if (num % 2 == 0) // 偶數
            {

                for (int i = 0; i < num; i += 2)
                {
                    Q = Q * 10 + (input[i] - '0');
                }
                for (int i = 1; i < num; i += 2)
                {
                    P = P * 10 + (input[i] - '0');
                }
            }
            else // 奇數
            {
                for (int i = 0; i < num; i += 2)
                {
                    P = P * 10 + (input[i] - '0');
                }
                for (int i = 1; i < num; i += 2)
                {
                    Q = Q * 10 + (input[i] - '0');
                }
            }
            sun = P - Q;
            printf("%d-%d=%d\n", P, Q, sun);
        }
    }
    return 0;
}