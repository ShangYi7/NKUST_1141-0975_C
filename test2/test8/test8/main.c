#include <stdio.h>
int f(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return f(n - 1) + f(n - 2);
    }
}
int main()
{
    int a;
    while (1)
    {
        scanf_s("%d", &a);
        if (a == -1)
        {
            break;
        }
        printf("F(%d)=%d\n", a, f(a));
    }

    return 0;
}