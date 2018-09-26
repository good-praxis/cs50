#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool argument_invalid(int, string);
string keyword_to_rot(string);
int get_diff(char);

int main(int argc, string argv[])
{
    if (argument_invalid(argc, argv[1]))
    {
        printf("Only accepts one alphabethic keyword argument!\n");
        return 1;
    }

    // Ran into problems grabbing the keyword length after the convertion to raw rotation, so grabbing it before
    int keyword_length = strlen(argv[1]);

    // Converting to upper so we have less problems working with it
    string keyword = keyword_to_rot(argv[1]);


    string input = get_string("plaintext: ");


    // i is the iterator, ki is the keyword iterator, n is the strlen of the plaintext, kl is the keyword length
    // we manually increment ki because we only incrememnt it if we encrypt a letter!
    for (int i = 0, ki = 0, n = strlen(input); i < n; i++)
    {

        // If this character isn't alphabethical we'll just skip over it
        if (!isalpha(input[i]))
        {
            continue;
        }

        int diff = (input[i] > 90) ? 96 : 64;

        // Takeoff casing
        input[i] -= diff;

        // Perform shift
        input[i] += keyword[ki];

        // Normalize input
        input[i] %= 26;

        // restore casing
        input[i] += diff;
        ki++;

        // Resetting the keyword iterator if it's bigger than the keyword length
        if (ki >= keyword_length)
        {
            ki = 0;
        }
    }

    printf("ciphertext: %s\n", input);

}

bool argument_invalid(int argc, string keyword)
{
    // Check if we got enough arguments in the first place
    if (argc != 2)
    {
        return true;
    }

    // If we got enough arguments we interate through the keyword to make sure it's all alphabethical!
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        if (!isalpha(keyword[i]))
        {
            return true;
        }
    }

    // If everything passes the keyword is valid!
    return false;
}

string keyword_to_rot(string input)
{
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        input[i] = toupper(input[i]);
        input[i] -= 65;
    }

    return input;
}
