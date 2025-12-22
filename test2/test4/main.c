#include <stdio.h>

int main()
{
    while (1)
    {
        int cash_50 = 0, cash_10 = 0, cash_5 = 0, cash_1 = 0;
        int total_cash = 0;
        int mode = 0;
        int drinks[] = {15, 23, 25, 37, 50};
        scanf_s("%d", &cash_50);
        if (cash_50 == -1)
        {
            return 0;
        }
        scanf_s("%d %d %d %d", &cash_10, &cash_5, &cash_1, &mode);
        total_cash = cash_50 * 50 + cash_10 * 10 + cash_5 * 5 + cash_1 * 1;
        if (drinks[mode - 1] <= total_cash)
        {
            total_cash -= drinks[mode - 1];
            cash_50 = total_cash / 50;
            total_cash %= 50;
            cash_10 = total_cash / 10;
            total_cash %= 10;
            cash_5 = total_cash / 5;
            total_cash %= 5;
            cash_1 = total_cash;
            printf("get:%d,change:%d %d %d %d\n", mode, cash_50, cash_10, cash_5, cash_1);
        }
        else
        {
            printf("get:NA,change:%d %d %d %d\n", cash_50, cash_10, cash_5, cash_1);
        }
    }
}