#include <stdio.h>
#define SIZE 15

int printHeader() {
    printf("Subscripts:\n");
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%3d ", i);
    }
    printf("\n");
    for (size_t i = 0; i < SIZE*4; i++)
    {
        printf("-");
    }
    printf("\n");
}

int printRow(int b[],int low,int mid,int high) {
    for (size_t i = 0; i < SIZE; i++)
    {
        if (low > i || high < i)
        {
            printf("    ");
        }
        else if (i == mid)
        {
            printf("%3d*", b[i]);
        }
        else
        {
            printf("%3d ", b[i]);
        }
    }
    printf("\n");
}

int binarySearch(const int b[],int key,int low,int high) { 
    int middle;
    while (low <= high)
    {
        middle = (low + high) / 2;
        printRow(b,low,middle,high);
        if (key == b[middle])
        {
            return middle;
        }
        else if (key < b[middle])
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }
    return -1;
}

int main() { 
    int a[SIZE];
    int key;
    int fuck;
    for (size_t i = 0; i < SIZE; i++)
    {
        a[i] = i * 2;
    }

    printf("請輸入 0 到 28 之間的數字: ");
    scanf_s("%d", &key);
    printHeader();

    fuck = binarySearch(a, key, 0, SIZE - 1);

    if (fuck != -1)
    {
        printf("找到 %d 在索引位置 %d\n", key, fuck);
    }
    else
    {
    
        printf("找不到 %d\n", key);
    }
}