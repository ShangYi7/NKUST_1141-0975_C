// 河內塔程式 三根柱子
// 有N個盤子與3個柱子, 要將最右邊的盤子全部移動至最左邊的柱子, 規
// 則為每次只能移動1個盤子, 且大盤子不能疊在小盤子上面, 遞迴為其經典解法
#include <stdio.h>

int move(int n, char source_A, char target_B, char auxiliary_C)
{
    // 如果只剩下 1 個盤子, 直接搬過去
    if (n == 1)
    {
        printf("move 1 from %c to %c\n", source_A, target_B);
        return 0;
    }

    // 把上面 n-1 個盤子, 從來源(A) 搬到 緩衝區(C)
    // 目標變成了 auxiliary_C
    move(n - 1, source_A, auxiliary_C, target_B);

    // 把最大的第 n 個盤子, 從來源(A) 搬到 目標(B)
    printf("move %d from %c to %c\n", n, source_A, target_B);

    // 把剛剛暫放在 緩衝區(C) 的 n-1 個盤子, 搬到 目標(B)
    // 來源變成了 auxiliary_C
    move(n - 1, auxiliary_C, target_B, source_A);

    return 0;
}

int main()
{
    while (1)
    {
        int plate = 0; // 盤子數量

        scanf("%d", &plate);
        if (plate == -1)
            break;
        move(plate, 'A', 'C', 'B');
    }
    //system("pause");
    return 0;
}

// 1 個牌子
// move 1 from A to C
// 2 個盤子
// move 1 from A to B
// move 2 from A to C
// move 1 from B to C
// 3 個盤子
// move 1 from A to C
// move 2 from A to B
// move 1 from C to B
// move 3 from A to C
// move 1 from B to A
// move 2 from B to C
// move 1 from A to C