#include <stdio.h>
#include <ctype.h> // 字元處理函式庫

int main()
{
    // 測試 isdigit() 判斷字元是否為數字
    printf("%s\n%s%s\n%s%s\n\n", "According to isdigit():", isdigit('8') ? "8 is a" : "8 is not a",
           "digit.", isalpha('#') ? "# is an" : "# is not an", "digit.");

    // 測試 isalpha() 判斷字元是否為大小寫字母
    printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "According to isalpha():", isalpha('A') ? "A is a" : "A is not a",
           "letter.", isalpha('b') ? "b is an" : "b is not an", "letter.",
           isalpha('&') ? "& is an" : "& is not an", "letter.",
           isalpha('4') ? "4 is an" : "4 is not an", "letter.");
    // 測試 isalnum() 判斷字元是否為數字或大小寫字母
    printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n", "According to isalnum():", isalnum('8') ? "8 is a" : "8 is not a",
           "digit or letter.", isalnum('A') ? "A is a" : "A is not a", "digit or letter.",
           isalnum('b') ? "b is a" : "b is not a", "digit or letter.",
           isalnum('&') ? "& is a" : "& is not a", "digit or letter.");
    // 測試 isxdigit() 判斷字元是否為十六進位數字
    printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n\n",
           "According to isxdigit():", isxdigit('8') ? "8 is a" : "8 is not a",
           "hexadecimal digit.", isxdigit('A') ? "A is a" : "A is not a", "hexadecimal digit.",
           isxdigit('b') ? "b is a" : "b is not a", "hexadecimal digit.",
           isxdigit('&') ? "& is a" : "& is not a", "hexadecimal digit.");
}
