#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int coins;
    float owed;
    int owedCents;

    while(true)
    {
        owed = get_float("Change owed: ");
        if (owed >= 0)
        {
            owedCents = round(owed * 100);
            break;
        }
    }



    // Let's first get the 25 cent pieces
    coins = owedCents / 25;

    // Now let's get the 10 cent pieces
    coins = coins + (owedCents % 25) / 10;

    // And let's get the 5 cents
    coins = coins + (owedCents % 25 % 10 / 5);

    // and let's finish up
    coins = coins + owedCents % 5;


    printf("%d\n", coins);

}