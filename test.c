#include <stdio.h>
#include <math.h>


int get_dig(long num, int len, int i);
int main(void)
{
    long num = 4003600000000014;
    int len = 16;
    int s_mul = 0;
    int s_sum = 0;
    int r;
    if (len % 2 == 0)
    {
          for (int i = 1; i <= len; i++)
          {
            if (i % 2 != 0)
            {
                r = 2 * get_dig(num, len, i);
                s_mul += (r % 10 + r / 10);
            }
            else
            {
                r = get_dig(num, len, i);
                s_sum += r;
            }
          }
    }
    printf("%i %i\n", s_sum, s_mul);
}


int get_dig(long num, int len, int i)
{
    int r = ((num / (pow(10, (len - i)))) % 10;
    printf("%i\n", r);
    return r;
}
