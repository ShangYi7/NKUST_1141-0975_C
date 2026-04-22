#include <stdio.h>
#define res_size 40
#define fre_size 11

int main(void)
{
    size_t ans;
    size_t rat;
    int fre[fre_size] = {0};
    int res[res_size] = {1, 2, 6, 4, 8, 5, 9, 7, 8, 10, 1, 6, 3, 8, 6, 10, 3, 8, 2, 7,
                         6, 5, 7, 6, 8, 6, 7, 5, 6, 6,  5, 6, 7, 5, 6, 4,  8, 6, 8, 10};
    // 計數
    for (ans = 0; ans < res_size;++ans)
    {
        // 如果 res[0] = 1，就會做 fre[1]++，如果 res[1] = 2，就會做 fre[2]++，以此類推
        ++fre[res[ans]];
    }
    printf("res\tfre\n");
    for (rat = 1; rat < fre_size; ++rat)
    {
        printf("%d\t%d\n", rat, fre[rat]);
    }
}