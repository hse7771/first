#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int lam_count;
    do
    {
        lam_count = get_int("Start size: ");
    }
    while (lam_count < 9);
    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (lam_count > end_size);
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (lam_count < end_size)
    {
        lam_count += (lam_count / 3 - lam_count / 4);
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
