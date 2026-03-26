#include <stdio.h>

int main()
{
    float data = 0;
    int a = 0;
    float b = 0;
    int cont = 1;
    int ans = 0;
    scanf_s("%f", &data);
    a = data;
    b = data - a;
    while (a != 0)
    {
        ans = ans + (a % 2) * cont;
        cont *= 10;
        a /= 2;
    }
    printf("%d", ans);
    if (b > 0)
    {
        printf(".");
        while (b != 0)
        {
            b *= 2;
            if (b >= 1)
            {
                ans = b;
                b -= 1;
            }
            else
            {
                ans = 0;
            }
            printf("%d", ans);
        }
    }
}