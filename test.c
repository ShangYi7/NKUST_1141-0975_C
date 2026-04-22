#include <stdio.h>

int main(){
    int y=10;
    int *p;
    p = &y; // p 指向 y 的位址
    printf("y = %d\n", y);
    // 印出指標 p 的值（即 y 的位址）
    printf("p = %p\n", p);
    // 印出 p 所指向的值（即 y 的值）
    printf("*p = %d\n", *p);
}