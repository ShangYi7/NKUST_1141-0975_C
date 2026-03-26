#include <stdio.h>

int main()
{
    int n;
    // 設定有幾位數
    while (scanf("%d", &n) > 1)
    {
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            // 填入數字到陣列
            scanf("%d", &arr[i]);
        }

        // 選擇排序法
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i > 0)
            {
                printf(" ");
            }
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
