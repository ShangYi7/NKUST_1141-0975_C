#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));  // 使用當前時間作為隨機數種子
    int a = rand() % 6 + 1; // 1~6
    int b = rand() % 6 + 1; // 1~6
    printf("Player rolled: %d + %d = %d\n", a, b,a+b);
    if (a + b == 7 || a + b == 11)
    {
        printf("Player wins\n");
    }
    else if(a+b==2||a+b==3||a+b==12){
        printf("Player loses\n");
    }
    else if(a + b == 4 || a + b == 5 || a + b == 6 || a + b == 8 || a + b == 9 || a + b == 10){
        int point = a + b;
        while (1)
        {
            a = rand() % 6 + 1; // 1~6
            b = rand() % 6 + 1; // 1~6
            printf("Player rolled: %d + %d = %d\n", a, b,a+b);
            if (a + b == point)
            {
                printf("Player wins\n");
                break;
            }
            else if (a + b == 7)
            {
                printf("Player loses\n");
                break;
            }
        }
    }
}