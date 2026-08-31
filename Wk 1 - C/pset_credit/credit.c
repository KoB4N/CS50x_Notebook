#include "cs50.h"
#include <stdio.h>

int calc_checksum(long card_num);
int get_len(long card_num);
int get_digit_one_two(long card_num);


int main(void) 
{
    long card_num;
    do
    {
        card_num = get_long("Number: ");
    } 
    while (card_num < 1);

    if (calc_checksum(card_num) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    int len = get_len(card_num);
    int digit_one_two = get_digit_one_two(card_num);
    int digit_one = digit_one_two / 10;

    if (len == 15 && (digit_one_two == 34 || digit_one_two == 37))
    {
        printf("AMEX\n");
    }
    else if (len == 16 && (digit_one_two >= 51 && digit_one_two <= 55))
    {
        printf("MASTERCARD\n");
    } 
    else if ((len == 13 || len == 16) && digit_one == 4)
    {
        printf("VISA\n");
    }
    else 
    {
        printf("INVALID\n");
    }
}


int calc_checksum(long card_num)
{
    int sum = 0;
    bool is_alt = false;

    while (card_num > 0)
    {
        int digit = card_num % 10;

        if (is_alt)
        {
            int prod = digit * 2;
            sum += (prod / 10) + (prod % 10); 
        }
        else 
        {
            sum += digit;
        }

        is_alt = !is_alt;
        card_num /= 10;
    }
    
    return sum;
}


int get_len(long card_num)
{
    int len = 0;
    while (card_num > 0)
    {
        card_num /= 10;
        len++;
    }
    return len;
}


int get_digit_one_two(long card_num) 
{
    while (card_num >= 100)
    {
        card_num /= 10;
    }
    return (int) card_num;
}