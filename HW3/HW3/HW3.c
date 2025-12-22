#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int d;
    while (1)
    {
        scanf("%d", &d);
        if (d != -1)
        {
            int x = 0;
            int i = 1;
            int temp = d;
            while (temp != 0)
            {
                int a = temp % 2;
                x = x + a * i;
                i *= 10;
                temp /= 2;
            }
            printf("%d\n", x);
        }
        else
        {
            return 0;
        }
    }
}
