#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    // Making sure we get the right amount of args
    if (argc != 2)
    {
        printf("Please provide only one non-negative integer argument!\n");
        return 1;
    }

    // Transforming Arg to int
    int rot = atoi(argv[1]);

    // This makes rot the smallest rot value we can properly work with
    rot = rot % 26;



    string input = get_string("plaintext: ");

    for (int i = 0, len = strlen(input); i < len; i++)
    {
        char c = input[i];
        int diff;

        // we calculate the most likely diff for the character
        if (c > 90)
        {
            diff = 96;
        }
        else
        {
            diff = 64;
        }


        //
        c -= diff;


        //if c isn't an ASCII character we continue
        if (c / 26 != 0 || c < 1)
        {
            continue;
        }

        //add rotation to c
        c += rot;

        //normalize c (flip around from z to a)
        c %= 26;

        // we re-add the diff inbefore we change the array
        input[i] = c + diff;

    }

    printf("ciphertext: %s\n", input);
    return 0;
}