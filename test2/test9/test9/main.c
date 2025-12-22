#include <stdio.h>

int main()
{
    int password;
    int data;
    int start=1;
    int end=100;
    scanf_s("%d", &password);
    printf("%d~%d\n", start, end);
    scanf_s("%d", &data);
    while (data != password)
    {
        if (data < password)
        {
            start = data + 1;
        }
        else
        {
            end = data - 1;
        }
        printf("%d~%d\n", start, end);
        scanf_s("%d", &data);
    }
    printf("PASS");

}