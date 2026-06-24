#include <stdio.h>

int main() {
    int c[7];
    // 讀取七張牌直到 EOF
    while (scanf("%d %d %d %d %d %d %d", &c[0], &c[1], &c[2], &c[3], &c[4], &c[5], &c[6]) == 7) {
        int rank_count[13] = {0}; // 記錄各點數數量 0-12 對應 2-A
        int suit_count[4] = {0};  // 記錄各花色數量 0=黑桃 1=紅心 2=方塊 3=梅花
        int suit_rank[4][14] = {0}; // 記錄各花色的各點數 (用來判斷同花順)
        int i, j;

        // 處理 7 張牌
        for (i = 0; i < 7; i++) {
            int suit = c[i] / 13; // 花色
            int rank = c[i] % 13; // 點數

            rank_count[rank]++; // 記錄點數
            suit_count[suit]++; // 記錄花色
            suit_rank[suit][rank] = 1; // 記錄花色的點數
            if (rank == 0) { // 將 A (0) 也作為最高牌 (13) 記錄，方便判斷順子（10, J, Q, K, A）
                suit_rank[suit][13] = 1;
            }
        }

        int pairs = 0, threes = 0, fours = 0; // 有幾個對子，三條，四條
        int has_flush = 0, has_straight = 0, has_straight_flush = 0; // 有沒有同花，順子，同花順

        // 統計對子、三條、四條的數量
        for (i = 0; i < 13; i++) {
            if (rank_count[i] == 2) pairs++;
            if (rank_count[i] == 3) threes++;
            if (rank_count[i] == 4) fours++;
        }

        // 判斷一般同花
        for (i = 0; i < 4; i++) {
            // 檢查有沒有花色大於五張
            if (suit_count[i] >= 5) has_flush = 1;
        }

        // 判斷一般順子
        int r_arr[14] = {0};
        for (i = 0; i < 13; i++) {
            if (rank_count[i]) r_arr[i] = 1;
        }
        if (rank_count[0]) r_arr[13] = 1;

        int consec = 0;
        for (i = 0; i < 14; i++) {
            // 只要中間有中斷就不是順子
            if (r_arr[i]) consec++;
            else consec = 0;

            if (consec >= 5) has_straight = 1;
        }

        // 判斷同花順
        for (i = 0; i < 4; i++) {
            if (suit_count[i] >= 5) { // 只有該花色超過5張才有可能是同花順
                consec = 0;
                for (j = 0; j < 14; j++) {
                    if (suit_rank[i][j]) consec++;
                    else consec = 0;

                    if (consec >= 5) has_straight_flush = 1;
                }
            }
        }

        // 依牌型大小由高到低判斷並輸出
        if (has_straight_flush) printf("Straight Flush\n"); // 同花順
        else if (fours) printf("Four of a Kind\n"); // 四條
        else if ((threes >= 1 && pairs >= 1) || threes >= 2) printf("Full House\n"); // 葫蘆
        else if (has_flush) printf("Flush\n"); // 同花
        else if (has_straight) printf("Straight\n"); // 順子
        else if (threes) printf("Three of a Kind\n"); // 三條
        else if (pairs >= 2) printf("Two Pair\n"); // 兩對
        else if (pairs == 1) printf("One Pair\n"); // 一對
        else printf("High Card\n"); // 高牌
    }
    return 0;
}
