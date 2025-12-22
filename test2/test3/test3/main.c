#include <stdio.h>

int main()
{
    int mode, data;

    scanf_s("%d %d", &mode, &data);
    switch (mode)
    {
    case 0: // 菱形

        break;
    case 1:
        for (int i = 0; i < data; i++)
        {
            for (int j = 0; j < data - i; j++)
                printf("*");
            printf("\n");
        }
        break;
    case 2:
        for (int i = 0; i < data; i++)
        {
            for (int j = 0; j <= i; j++)
                printf("*");
            printf("\n");
        }
        break;
    case 3:
        for (int i = 0; i < data; i++)
        {
            for (int s = 0; s < data - i - 1; s++)
                printf(" ");
            for (int j = 0; j <= i; j++)
                printf("*");
            printf("\n");
        }
        break;
    case 4:
        for (int i = 0; i < data; i++)
        {
            for (int s = 0; s < i; s++)
                printf(" ");
            for (int j = 0; j < data - i; j++)
                printf("*");
            printf("\n");
        }
        break;
    }
    return 0;
}
