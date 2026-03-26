#include <stdio.h>

void hanoi(int n, char A, char C, char B)
{
    if (n == 1)
    {
        printf("move 1 A %c C %c\n", A, C);
        return;
    }
    hanoi(n - 1, A, B, C);
    printf("move %d A %c C %c\n", n, A, C);
    hanoi(n - 1, B, C, A);
}

int main()
{
    int n;
    while (scanf("%d", &n) && n != -1)
    {
        hanoi(n, 'A', 'C', 'B');
    }
    return 0;
}
