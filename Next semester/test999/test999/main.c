#include <stdio.h>

int main()
{
    int n;
    int temp;
    int arr[100];
    int i, j; // Dev C++ 不能在 迴圈 宣告變數 (C90)
    while (scanf_s("%d", &n) != EOF && n > 0)
    {
        for (i = 0; i < n; i++)
        {
            scanf_s("%d", &arr[i]);
        }

        // 交換排序
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
