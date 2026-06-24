#include <stdio.h>

int main(){
    int data[7]={0}; //

    while(scanf("%d %d %d %d %d %d %d", &data[0], &data[1], &data[2], &data[3], &data[4], &data[5], &data[6]) == 7){
        int suit_count[4]={0}; //記錄花色數量
        int face_count[14]={0}; //記錄點數數量
        int suit_rank[4][14]={0}; //記錄花色的點數
        int i,j;
        int count;

        for(i=0;i<7;i++){
            int suit=data[i]/13;
            int face=data[i]%13;
            face_count[face]++;
            suit_count[suit]++;
            suit_rank[suit][face]=1;
            if(face==0){
                suit_rank[suit][13]=1;
                face_count[13]++;
            }
        }
        int pairs = 0, threes = 0, fours = 0; // 有幾個對子，三條，四條
        int has_flush = 0, has_straight = 0, has_straight_flush = 0; // 有沒有同花，順子，同花順

        for(i=0;i<13;i++){
            if(face_count[i]==2) pairs++;
            if(face_count[i]==3) threes++;
            if(face_count[i]==4) fours++;
        }

        // 順子
        count=0;
        for(i=0;i<14;i++){
            if(face_count[i])count++;
            else count=0;
            if(count>=5)has_straight=1;
        }

        // 同花
        for(i=0;i<4;i++){
            if(suit_count[i]>=5) has_flush=1;
        }

        //同花順
        for(i=0;i<4;i++){
            count=0;
            for(j=0;j<14;j++){
                if(suit_rank[i][j])count++;
                else count=0;
                if(count>=5)has_straight_flush=1;
            }
        }

        //判斷牌型
        if(has_straight_flush)printf("Straight Flush\n");
        else if(fours)printf("Four of a Kind\n");
        else if((threes>=1 && pairs>=1)||threes>=2)printf("Full House\n");
        else if(has_flush)printf("Flush\n");
        else if(has_straight)printf("Straight\n");
        else if(threes)printf("Three of a Kind\n");
        else if(pairs>=2)printf("Two Pair\n");
        else if(pairs==1)printf("One Pair\n");
        else printf("High Card\n");
    }
}