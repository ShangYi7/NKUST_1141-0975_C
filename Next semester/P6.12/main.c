#include <stdio.h>

int main(void)
{
    char s[100];
    printf("\tarray: %p\n\t&array[0]: %p\n\t&array: %p\n", s, &s[0], &s);
    // %p 是 printf 用來輸出「指標位址」的格式指定符。
    // 陣列的名稱和第一個元素的位址是相同的，所以 s 和 &s[0] 會輸出相同的位址。
    // &s 是陣列的位址，與 s 和 &s[0] 的位址相同，但在某些情況下可能會有不同的行為，特別是在指標運算中。
}