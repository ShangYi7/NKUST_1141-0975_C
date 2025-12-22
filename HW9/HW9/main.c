#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char input[100];
int num, P = 0, Q = 0;
int sun;

int divide(char input[])
{
    // strlen() 計算字串長度
    int num = strlen(input);
    P = 0;
    Q = 0;

    if (num % 2 == 0)
    {
        for (int i = 1; i <= num - 1; i += 2)
        {
            P = (P) * 10 + (input[i] - '0');
        }
        for (int i = 0; i <= num - 1; i += 2)
        {
            Q = (Q) * 10 + (input[i] - '0');
        }
    }
    else
    {
        for (int i = 1; i <= num - 1; i += 2)
        {
            Q = (Q) * 10 + (input[i] - '0');
        }
        for (int i = 0; i <= num - 1; i += 2)
        {
            P = (P) * 10 + (input[i] - '0');
        }
    }
    sun = P - Q;
    printf("%d-%d=%d\n", P, Q, sun);

    return sun;
}

int main(void)
{
    while (1)
    {
        scanf("%s", input);
        if (input[0] == '-')
            break;

        // Divide
        sun = divide(input);

        // Subtraction
        while (1)
        {
            if (sun >= 10)
            {
                // sptinf == 把結果存在陣列中
                // sprintf(字串陣列, 格式, 變數);
                sprintf(input, "%d", sun);
                sun = divide(input);
            }
            else
            {
                break;
            }
        }
    }

    //system("pause");
    return 0;
}
