// HW9 - 文物編冊系統
// 使用動態記憶體配置 + 排序後二分搜尋判斷重複 ID
// NOTE: 使用平行陣列取代結構體陣列，減少記憶體峰值用量
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOL 600

/**
 * qsort 比較函式：比較兩個 unsigned int 值
 */
int cmp_uint(const void *a, const void *b)
{
    unsigned int va = *(const unsigned int *)a;
    unsigned int vb = *(const unsigned int *)b;
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}

/**
 * 二分搜尋：在已排序的陣列中查找目標值
 * @param arr 已排序的陣列
 * @param n 陣列長度
 * @param target 搜尋目標
 * @returns 是否找到 (1=找到, 0=未找到)
 */
int binary_search(const unsigned int *arr, int n, unsigned int target)
{
    int lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return 1;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return 0;
}

int main(void)
{
    int cap = 4096, n = 0;

    // NOTE: 使用兩個平行陣列分別存 ID 和卷號，比結構體更省記憶體
    unsigned int *all_ids = (unsigned int *)malloc(sizeof(unsigned int) * cap);
    int *all_vols = (int *)malloc(sizeof(int) * cap);

    int vol;
    unsigned int id;

    // 讀取所有輸入資料直到 EOF
    while (scanf("%d %x", &vol, &id) == 2)
    {
        if (n >= cap)
        {
            cap *= 2;
            all_ids = (unsigned int *)realloc(all_ids, sizeof(unsigned int) * cap);
            all_vols = (int *)realloc(all_vols, sizeof(int) * cap);
        }
        all_ids[n] = id;
        all_vols[n] = vol;
        n++;
    }

    // --- 步驟 1: 複製 ID 並排序，偵測重複 ---
    // NOTE: 只複製 ID 值（4 bytes/筆）而非整個結構體，大幅降低峰值記憶體
    unsigned int *sorted_ids = (unsigned int *)malloc(sizeof(unsigned int) * (n > 0 ? n : 1));
    for (int i = 0; i < n; i++) sorted_ids[i] = all_ids[i];
    qsort(sorted_ids, n, sizeof(unsigned int), cmp_uint);

    // 掃描排序後的陣列，收集出現 >= 2 次的 ID（去重後存入 rep）
    int rep_cap = 256, rep_n = 0;
    unsigned int *rep = (unsigned int *)malloc(sizeof(unsigned int) * rep_cap);

    for (int i = 0; i < n; )
    {
        int j = i + 1;
        while (j < n && sorted_ids[j] == sorted_ids[i]) j++;
        if (j - i >= 2)
        {
            if (rep_n >= rep_cap)
            {
                rep_cap *= 2;
                rep = (unsigned int *)realloc(rep, sizeof(unsigned int) * rep_cap);
            }
            rep[rep_n++] = sorted_ids[i];
        }
        i = j;
    }
    free(sorted_ids); // 排序副本已不需要

    // --- 步驟 2: 按卷號分組，直接存入各卷的 ID 列表 ---
    int vol_n[MAX_VOL];
    int vol_c[MAX_VOL];
    unsigned int *vol_data[MAX_VOL];

    for (int v = 0; v < MAX_VOL; v++)
    {
        vol_n[v] = 0;
        vol_c[v] = 0;
        vol_data[v] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        // 使用二分搜尋快速判斷此 ID 是否為重複樣本
        if (binary_search(rep, rep_n, all_ids[i])) continue;

        int v = all_vols[i];
        if (vol_n[v] >= vol_c[v])
        {
            vol_c[v] = (vol_c[v] == 0) ? 4 : vol_c[v] * 2;
            vol_data[v] = (unsigned int *)realloc(vol_data[v], sizeof(unsigned int) * vol_c[v]);
        }
        vol_data[v][vol_n[v]++] = all_ids[i];
    }

    // 原始資料已分配完畢，釋放以節省記憶體
    free(all_ids);
    free(all_vols);

    // --- 步驟 3: 依卷號輸出 ---
    for (int v = 0; v < MAX_VOL; v++)
    {
        if (vol_n[v] == 0) continue;
        printf("%d(%d):", v, vol_n[v]);
        for (int j = 0; j < vol_n[v]; j++)
        {
            printf(" 0x%08X", vol_data[v][j]);
        }
        printf("\n");
    }

    // --- 步驟 4: 輸出重複報告 ---
    printf("Repeated IDs:");
    for (int i = 0; i < rep_n; i++)
    {
        printf(" 0x%08X", rep[i]);
    }
    printf("\n");

    // 釋放所有動態記憶體
    for (int v = 0; v < MAX_VOL; v++) free(vol_data[v]);
    free(rep);

    return 0;
}
