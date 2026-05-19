#include <stdio.h>
#include <stdlib.h>

// 牌型強度：數字越大代表牌型越強
enum HandRank
{
    HIGH_CARD = 0,
    STRAIGHT = 1,
    FLUSH = 2,
    FULL_HOUSE = 3,
    FOUR_OF_A_KIND = 4,
    STRAIGHT_FLUSH = 5
};

// qsort 用的比較函式：由小到大排序點數
static int compare_int(const void *a, const void *b)
{
    int left = *(const int *)a;
    int right = *(const int *)b;
    return (left > right) - (left < right);
}

// 判斷 5 張牌的點數是否連續，也就是順子
// 先排序，再檢查每一張是否都比前一張大 1
static int is_consecutive(int ranks[5])
{
    int i;

    // 先把點數排序，後面才方便檢查是否連號
    qsort(ranks, 5, sizeof(int), compare_int);

    for (i = 1; i < 5; i++)
    {
        // 有重複點數就不可能是順子
        if (ranks[i] == ranks[i - 1])
        {
            return 0;
        }
        // 不是連續遞增 1，也不是順子
        if (ranks[i] != ranks[i - 1] + 1)
        {
            return 0;
        }
    }

    return 1;
}

// 評估 5 張牌的牌型，回傳對應的 HandRank
static int evaluate_five_cards(const int cards[5])
{
    int rank_count[13] = {0};
    int suit_count[4] = {0};
    int ranks[5];
    int i;
    int pair_count = 0;
    int three_count = 0;
    int four_count = 0;
    int flush = 0;
    int straight = 0;

    // 依序拆出花色與點數，並統計每種點數、花色出現次數
    for (i = 0; i < 5; i++)
    {
        int suit = cards[i] / 13;
        int rank = cards[i] % 13;

        ranks[i] = rank;
        rank_count[rank]++;
        suit_count[suit]++;
    }

    // 若某一種花色剛好出現 5 次，表示這 5 張牌是同花
    for (i = 0; i < 4; i++)
    {
        if (suit_count[i] == 5)
        {
            flush = 1;
            break;
        }
    }

    // 統計四條、三條、對子個數，後面用來判斷葫蘆與四條
    for (i = 0; i < 13; i++)
    {
        if (rank_count[i] == 2)
        {
            pair_count++;
        }
        else if (rank_count[i] == 3)
        {
            three_count++;
        }
        else if (rank_count[i] == 4)
        {
            four_count++;
        }
    }

    // 先檢查一般順子：A 不能當作高點數，直接照 0~12 的順序看
    if (is_consecutive(ranks))
    {
        straight = 1;
    }
    else
    {
        // 再補查 A2345 以外的 A 當高牌情況：把 A 視為 13 再檢查一次
        int ranks_ace_high[5];
        int has_ace = 0;

        for (i = 0; i < 5; i++)
        {
            ranks_ace_high[i] = ranks[i];
            if (ranks_ace_high[i] == 0)
            {
                // A 改成比 K 更大的點數來測試是否能形成順子
                ranks_ace_high[i] = 13;
                has_ace = 1;
            }
        }

        // 若有 A 且轉換後連號，表示是 A 當高牌的順子
        if (has_ace && is_consecutive(ranks_ace_high))
        {
            straight = 1;
        }
    }

    // 依照牌型強度由高到低回傳結果
    if (straight && flush)
    {
        return STRAIGHT_FLUSH;
    }
    if (four_count == 1)
    {
        return FOUR_OF_A_KIND;
    }
    if (three_count == 1 && pair_count == 1)
    {
        return FULL_HOUSE;
    }
    if (flush)
    {
        return FLUSH;
    }
    if (straight)
    {
        return STRAIGHT;
    }

    return HIGH_CARD;
}

// 把牌型代碼轉成題目要求的英文名稱
static const char *hand_name(int rank)
{
    switch (rank)
    {
        case STRAIGHT_FLUSH:
            return "Straight Flush";
        case FOUR_OF_A_KIND:
            return "Four of a Kind";
        case FULL_HOUSE:
            return "Full House";
        case FLUSH:
            return "Flush";
        case STRAIGHT:
            return "Straight";
        default:
            return "High Card";
    }
}

int main()
{
    int cards[7];

    // 每次讀入 7 張不重複的牌，直到 EOF 為止
    while (scanf("%d %d %d %d %d %d %d", &cards[0], &cards[1], &cards[2], &cards[3], &cards[4],
                 &cards[5], &cards[6]) == 7)
    {
        int best_rank = HIGH_CARD;
        int i, j, k, l, m;

        // 枚舉 7 張牌中任選 5 張的所有組合，共 21 種
        for (i = 0; i < 7; i++)
        {
            for (j = i + 1; j < 7; j++)
            {
                for (k = j + 1; k < 7; k++)
                {
                    for (l = k + 1; l < 7; l++)
                    {
                        for (m = l + 1; m < 7; m++)
                        {
                            // 取出其中一組 5 張牌，計算它的牌型
                            int five[5] = {cards[i], cards[j], cards[k], cards[l], cards[m]};
                            int rank = evaluate_five_cards(five);

                            // 保留目前為止最強的牌型
                            if (rank > best_rank)
                            {
                                best_rank = rank;
                            }
                        }
                    }
                }
            }
        }

        // 輸出最佳 5 張牌所對應的牌型名稱
        printf("%s\n", hand_name(best_rank));
    }

    return 0;
}