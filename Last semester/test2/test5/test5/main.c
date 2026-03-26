#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int mode;
    int a, b;
    while (1)
    {
        scanf("%d", &mode);
        if (mode == -1)
        {
            return 0;
        }
        scanf("%d %d", &a, &b);

        switch (mode)
        {
            case 1: // 最大公因數
                while (b != 0)
                {
                    int temp = a % b;
                    a = b;
                    b = temp;
                }
                printf("%d\n", a);
                break;

            case 2: // 最小公倍數
            {
                int temp = 1;
                while (1)
                {
                    if (temp % a == 0 && temp % b == 0)
                    {
                        printf("%d\n", temp);
                        break;
                    }
                    temp++;
                }
                break;
            }
        }
    }
    return 0;
}