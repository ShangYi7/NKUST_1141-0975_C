// 請設計一程式，此程式會不斷要求使用者輸入十進位整數，請印出該整數的二進位數，直到輸入的數為-1 則程式結束。(輸入的範圍為-1 ~ 100)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int data=0,ans=0,x=0,temp=0;
    while (1)
    {
        data = 0, ans = 0, x = 0, temp = 0;
        scanf("%d",&data);
        if(data==-1)
        {
            return 0; //結束程式
        }
        else
        {
            for(x=1;data>=2;x*=10){
                temp=data%2; //取得餘數
                data=data/2; //取得商
                ans=ans+temp*x; //將餘數 x 上位數後加總
                if (data < 2) {
                    ans = ans + data * x * 10; //將最後的商 x 上位數後加總
                    printf("%d\n", ans);
                }
            }
        }
    }
}