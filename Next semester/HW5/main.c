#include <stdio.h>
#include <stdlib.h>

int main()
{
    int o, n; // o:字母層數, n：半徑

    while (scanf("%d %d", &o, &n) == 2)
    {
        if (o < 1 || o > 26 || n <= 0)
            break;

        int size = 2 * n - 1; // 矩形邊長
        int c = n - 1;         // 中心點座標

        // 逐格判斷目前所在層數並印出對應字母
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int di = abs(i - c); // 距離中心點的列方向距離
                int dj = abs(j - c); // 距離中心點的行方向距離
                int layer;           // 目前所在的矩形層數

                // 取較大距離，代表目前格子離中心有多遠
                if (di > dj)
                    layer = di;
                else
                    layer = dj;

                // 依層數決定要印出的字母，超過 O 時循環回 A
                putchar('A' + layer % o);
            }
            putchar('\n');
        }
    }

    return 0;
}