#include <stdio.h>
#define SIZE 15

void printHeader(void)
{
    size_t i;
    printf("\nSubscripts:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%3d ", i);
    }

    printf("\n");

    for (i = 0; i < 4 * SIZE; i++)
    {
        printf("-");
    }
    printf("\n");
}

void printRow(const int b[],size_t low,int mid,size_t hig){
    size_t i;
    for ( i = 0; i < SIZE; i++)
    {
        if(i<low || i>hig){
            printf("    ");
        }
        else if(i==mid){
            printf("%3d*", b[i]);
        }
        else{
            printf("%3d ", b[i]);
        }
    }
    printf("\n");
}

int binarySearch(const int b[], int searchKey, size_t low, size_t high)
{
    int middle;
    while (low<=high)
    {
        middle = (low + high) / 2;
        printRow(b, low, middle, high);

        if(searchKey==b[middle]){
            return middle;
        }
        else if(searchKey<b[middle]){
            high = middle - 1;
        }
        else{
            low = middle + 1;
        }
    }
    return -1;
}

int main()
{
    int a[SIZE];
    int key;
    size_t i;
    int result;
    for (i = 0; i < SIZE; i++)
    {
        a[i] = i * 2;
    }
    printf("請輸入 0 到 28 之間的數字: ");
    scanf("%d", &key);

    printHeader();

    result = binarySearch(a, key, 0, SIZE - 1);

    if(result != -1){
        printf("找到 %d 在索引位置 %d\n", key, result);
    }
    else{
        printf("找不到 %d\n", key);
    }

}