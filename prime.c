#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    int div = 2;
    if (number == 1)
    {
        return false;
    }
    if (number % 2 == 0)
    {
        return number == 2;
    }
    while (div * div <= number && number % div != 0)
    {
        div++;
    }
    return div * div > number;
}
