#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // initilization
    long long input;
    int sum = 0;
    string result;
    string identify_card(int, int);
    string checksum(int, string);

    // Gets valid input
    while (true)
    {
        input = get_long_long("Number: ");
        if (input)
        {
            break;
        }
    }


    for (int i = 1; input > 0 ; i++)
    {
        int digit = (int)(input % 10);

        // Every second number is multiplied by 2 and it's digits are added to the sum
        if (i % 2 == 0)
        {
            digit = digit * 2;
            if (digit >= 10)
            {
                sum = sum + digit / 10;
            }
            sum = sum + digit % 10;


        }

        // Every other number is added to the sum directly
        else
        {
            sum = sum + digit;
        }

        // Once we reach the last two digits we determine the card type
        if (input < 100 && input > 10)
        {
            result = identify_card((int) input, i);
        }

        // After every iteration we take off the last digit of the input
        input = input / 10;
    }

    // Last but not least we take the checksum
    printf("%s", checksum(sum, result));

}

// This function determines which brand the card has (overwritten by checksum)
string identify_card(int digits, int length)
{
    // Visa has 4X cards, lenght 13 or 16 (-1 here)
    if (digits / 10 == 4 && (length == 12 || length == 15))
    {
        return "VISA\n";
    }

    // Mastercard starts with 51-55, has a length of 16
    else if ((digits >= 51 && digits <= 55) && length == 15)
    {
        return "MASTERCARD\n";
    }

    // AMEX starts on 34 or 37 and has a length of 15
    else if ((digits == 34 || digits == 37) && length == 14)
    {
        return "AMEX\n";
    }

    // Else invalid
    else
    {
        return "INVALID\n";
    }
}

// Performs checksum on the card
string checksum(int sum, string cardtype)
{
    if (sum % 10 == 0)
    {
        return cardtype;
    }
    return "INVALID\n";
}