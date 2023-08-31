#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int calc_ch_s(long num, int len);
int get_length(long num);
void card_type(long num, int len, int req1);
int calc_ch_s(long num, int len);
int get_dig(long num, int len, int i);
int main(void)
{
    long card_num;
    do
    {
        card_num = get_long("Number: ");
    }
    while (isalnum(card_num));
    int len = get_length(card_num);
    int req1 = calc_ch_s(card_num, len);
    card_type(card_num, len, req1);
}

int get_length(long num)
{
    int c = 0;
    while (num > 0)
    {
        num = num / 10;
        c++;
    }
    return c;
}

int get_dig(long num, int len, int i)
{
    int r = ((long)(num / (pow(10, (len - i))))) % 10;
    return r;
}

int calc_ch_s(long num, int len)
{
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
    else
    {
        for (int i = 1; i <= len; i++)
          {
            if (i % 2 == 0)
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
    return ((s_sum + s_mul) % 10 == 0);
}

void card_type(long num, int len, int req1)
{
    int fst_dig = num / (pow(10, (len - 1)));
    int scnd_dig = num / (pow(10, (len - 2)));
    if (req1)
    {
        if (len == 15 && fst_dig == 3 && (scnd_dig == 4 || scnd_dig == 7))
        {
            printf("American Express\n");
        }
        else if ((len == 13 || len == 16) && fst_dig == 4)
        {
            printf("VISA\n");
        }
        else if (len == 16 && fst_dig == 5 && scnd_dig >= 1 && scnd_dig <= 5)
        {
            printf("MasterCard\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
