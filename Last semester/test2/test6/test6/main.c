#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int P = 0, Q = 0;
    int num, sum;
    char input[100];
    while (1)
    {
        scanf("%s", input);
        if(input[0]=='-') break;    
        P = 0;
        Q = 0;
        num = strlen(input);
        P = 0;
        Q = 0;
        if (num % 2 == 0)
        {
            for (int i = 1; i <= num - 1; i += 2)
            {
                P = P * 10 + (input[i] - '0');
            }
            for (int i = 0; i < num; i += 2)
            {
                Q = Q * 10 + (input[i] - '0');
            }
            // printf("%d %d",P,Q);
        }
        else
        {
            for (int i = 1; i <= num - 1; i += 2)
            {
                Q = Q * 10 + (input[i] - '0');
            }
            for (int i = 0; i < num; i += 2)
            {
                P = P * 10 + (input[i] - '0');
            }
            // printf("%d %d", P, Q);
        }
        sum = P - Q;
        printf("%d-%d=%d\n", P, Q, sum);
        while (sum >= 10)
        {
            sprintf(input, "%d", sum);
            num = strlen(input);
            P = 0;
            Q = 0;
            if (num % 2 == 0)
            {
                for (int i = 1; i <= num - 1; i += 2)
                {
                    P = P * 10 + (input[i] - '0');
                }
                for (int i = 0; i < num; i += 2)
                {
                    Q = Q * 10 + (input[i] - '0');
                }
                // printf("%d %d",P,Q);
            }
            else
            {
                for (int i = 1; i <= num - 1; i += 2)
                {
                    Q = Q * 10 + (input[i] - '0');
                }
                for (int i = 0; i < num; i += 2)
                {
                    P = P * 10 + (input[i] - '0');
                }
            }
            sum = P - Q;
            printf("%d-%d=%d\n", P, Q, sum);
        }
    }
}