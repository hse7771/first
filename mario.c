#include <cs50.h>
#include <stdio.h>

void build_pyramid(int n);
int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n > 8 || n < 1);
    build_pyramid(n);
}

void build_pyramid(int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int g = n - i; g >= 1; g--)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
