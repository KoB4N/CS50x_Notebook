#include "cs50.h"
#include <stdio.h>

int main(void) 
{
    int quarter_cnt = 0;
    int dime_cnt = 0;
    int nickel_cnt = 0;
    int penny_cnt = 0;
    int change;
    int sum;

    do 
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    while (change >= 25)
    {
        change -= 25;
        quarter_cnt += 1;
    }

    while (change >= 10)
    {
        change -= 10;
        dime_cnt += 1;
    }

    while (change >= 5)
    {
        change -= 5;
        nickel_cnt += 1;
    }

    while (change >= 1)
    {
        change -= 1;
        penny_cnt += 1;
    }
        
    sum = quarter_cnt + dime_cnt + nickel_cnt + penny_cnt;
    printf("%i\n", sum);
}