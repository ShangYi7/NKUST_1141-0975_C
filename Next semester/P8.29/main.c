#include <stdio.h>
#include <stdlib.h>

int main(){
    const char *str = "-2131289asdf";
    long int l;
    char *endstr;
    l = strtol(str, &endstr, 10);
    printf("Value: %ld\n", l);
    printf("沒有轉換的部分: %s\n", endstr);
    return 0;
}