#include <stdio.h>
#define SIZE 15

// 二元搜尋
// 取中間值, 左右比較

// 前置宣告：讓 binarySearch 先知道下面的輸出輔助函式
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);

// binarySearch: 在「已排序」陣列中用二分搜尋找目標值
// 找到時回傳索引位置，找不到則回傳 -1
int binarySearch(const int b[], int searchKey, size_t low, size_t high)
{
    int middle; //中間值
    while (low <= high)
    {
        // 取目前搜尋區間的中間點，二分搜尋就是每次把範圍砍半
        middle = (low + high) / 2;
        // 先把目前的搜尋區間印出來，方便觀察每一步的縮小過程
        printRow(b, low, middle, high);

        // 中間值剛好等於目標：代表已經找到
        if (searchKey == b[middle])
        {
            return middle;
        }
        // 目標比中間值小，代表只需要往左半邊繼續找
        else if (searchKey < b[middle])
        {
            high = middle - 1;
        }
        // 目標比中間值大，代表只需要往右半邊繼續找
        else
        {
            low = middle + 1;
        }
    }
    // 迴圈結束還沒找到，就回傳 -1 表示失敗
    return -1;
}

// 印出陣列索引列，讓使用者先對照每個位置的下標
void printHeader(void)
{
    unsigned int i;
    puts("\nSubscripts:");
    for (i = 0; i < SIZE; i++)
    {
        printf("%3u ", i);
    }

    printf("\n");

    // 畫出分隔線，讓索引列和資料列更容易閱讀
    for (size_t i = 0; i < 4 * SIZE; i++)
    {
        printf("%s", "-");
    }

    printf("\n");
}

// 印出目前搜尋區間的資料列，mid 位置會用 * 標示
// 區間外的元素會留白，這樣可以直接看出每一輪搜尋縮小到哪裡
void printRow(const int b[], size_t low, size_t mid, size_t high)
{
    size_t i;

    for (i = 0; i < SIZE; i++)
    {
        // 不在目前搜尋範圍內的元素不顯示內容，只保留對齊空白
        if (i < low || i > high)
        {
            printf("%s", "    ");
        }
        // 中間點是本輪比較的重點，用 * 標記出來
        else if (i == mid)
        {
            printf("%3d*", b[i]);
        }
        // 其他仍在搜尋範圍內的元素照常輸出
        else
        {
            printf("%3d ", b[i]);
        }
    }

    puts("");
}

int main()
{
    int a[SIZE];
    size_t i;
    int key;    // 尋找目標
    int result; // 結果

    // 建立已排序的偶數陣列：0, 2, 4, ..., 28
    // binary search 的前提就是資料必須先排序好
    for (i = 0; i < SIZE; i++)
    {
        a[i] = 2 * i;
    }

    // 讀入要搜尋的值
    printf("請輸入 0 到 28 之間的數字: ");
    scanf("%d", &key);

    printHeader();

    // 執行搜尋，回傳找到的索引；若沒找到則回傳 -1
    result = binarySearch(a, key, 0, SIZE - 1);

    // 根據回傳值判斷搜尋結果
    if(result != -1){
        printf("找到 %d 在索引位置 %d\n", key, result);
    }
    else{
        printf("找不到 %d\n", key);
    }
}