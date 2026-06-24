#include <stdio.h>
#define SIZE 80

// 把字串反轉的函式
void reverse(const char *const sPtr)
{
    // sPtr[0] == *sPtr
    // sPtr[1] == *(sPtr + 1)
    if ('\0' == sPtr[0])
    {
        return;
    }
    else
    {
        reverse(&sPtr[1]);
        putchar(sPtr[0]);
    }
}

int main()
{
    char str[SIZE];
    printf("Enter a string: ");
    // fgets(字元陣列, 最多讀取數量, 來源);
    // stdin 是標準輸入，通常是鍵盤
    fgets(str, SIZE, stdin);
    printf("The reversed string is: ");
    reverse(str);
    return 0;
}
