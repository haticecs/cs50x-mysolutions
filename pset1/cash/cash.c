#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollar;
    int count = 0;
    
    do
    {
        dollar = get_float("Change owed: ");

    }
    while (!(dollar > 0));
    
    int ownedCoin = round(dollar * 100);
   
   
    if ((ownedCoin / 25) > 0)
    {
        count += ownedCoin / 25;
        ownedCoin = ownedCoin % 25;
    }
    if ((ownedCoin / 10) > 0)
    {
        count += ownedCoin / 10;
        ownedCoin = ownedCoin % 10;
    }
    if ((ownedCoin / 5) > 0)
    {
        count += ownedCoin / 5;
        ownedCoin = ownedCoin % 5;
    }
    if ((ownedCoin) > 0)
    {
        count += ownedCoin;
    }
    
    printf("%i\n", count);
    
}
