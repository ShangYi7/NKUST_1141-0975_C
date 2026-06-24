#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char *str = "321.1 asvb";
    double d;
    char *endstr;
    d = strtod(str, &endstr);
    printf("Value: %.1f\n", d);
    printf("沒有轉換的部分: %s\n", endstr);
    return 0;
}