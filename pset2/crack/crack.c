#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

bool crack_one_letter_password(void);
bool crack_two_letter_password(void);
bool crack_three_letter_password(void);
bool crack_four_letter_password(void);
bool crack_five_letter_password(void);
bool crack_password(string);


string salt_possibilities = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
string key_possibilities = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string hash = "";



int main(int argc, string argv[])
{
    // Checking arguments
    if (argc != 2)
    {
        printf("Please use a password hash as argument!\n");
        return 1;
    }
    hash = argv[1];

    // "Easiest" way to do this, exhaustively checking for one, then two, then three... letter passwords
    if (crack_one_letter_password())
    {
        return 0;
    }
    else if (crack_two_letter_password())
    {
        return 0;
    }
    else if (crack_three_letter_password())
    {
        return 0;
    }
    else if (crack_four_letter_password())
    {
        return 0;
    }
    else if (crack_five_letter_password())
    {
        return 0;
    }

    // Otherwise something went really wrong, this should never happen (and timewise will never happen)
    return 1;
}

bool crack_one_letter_password()
{
    // just a simple loop, adding the possibility to a null char
    for (int i = 0; i < 52; i++)
    {
        // This, canonically is a char array, but we need to transform it into a char* array, by assigning it to a string (easiest way imo)
        char password_array[2] = {key_possibilities[i], key_possibilities[52]};
        string password = password_array;
        if (crack_password(password))
        {
            return true;
        }
    }
    return false;
}

bool crack_two_letter_password()
{
    // 2 nested loop, two characters plus null char
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            // This, canonically is a char array, but we need to transform it into a char* array, by assigning it to a string (easiest way imo)
            char password_array[3] = {key_possibilities[i], key_possibilities[j], key_possibilities[52]};
            string password = password_array;
            if (crack_password(password))
            {
                return true;
            }
        }
    }
    return false;
}

bool crack_three_letter_password()
{
    // 3 nested loop, 3 characters plus null char
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                // This, canonically is a char array, but we need to transform it into a char* array, by assigning it to a string (easiest way imo)
                char password_array[4] = {key_possibilities[i], key_possibilities[j], key_possibilities[k], key_possibilities[52]};
                string password = password_array;
                if (crack_password(password))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool crack_four_letter_password()
{
    // 4-nested loops, 4 characters + null char
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                for (int l = 0; l < 52; l++)
                {
                    // This, canonically is a char array, but we need to transform it into a char* array, by assigning it to a string (easiest way imo)
                    char password_array[5] = {key_possibilities[i], key_possibilities[j], key_possibilities[k], key_possibilities[l], key_possibilities[52]};
                    string password = password_array;
                    if (crack_password(password))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


bool crack_five_letter_password()
{
    // 5-nested loops, 5 characters + null char
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                for (int l = 0; l < 52; l++)
                {
                    for (int m = 0; m < 52; m++)
                    {
                        // This, canonically is a char array, but we need to transform it into a char* array, by assigning it to a string (easiest way imo)
                        char password_array[6] = {key_possibilities[i], key_possibilities[j], key_possibilities[k], key_possibilities[l], key_possibilities[m], key_possibilities[52]};
                        string password = password_array;
                        if (crack_password(password))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}


// This tests a password with all possible salts
bool crack_password(string password)
{
    // Double loop because we have to characters in a salt
    for (int salt_one = 0; salt_one < 64; salt_one++)
    {
        for (int salt_two = 0; salt_two < 64; salt_two++)
        {
            //ending on a null char to terminate the string
            // This, canonically is a char array, but we need to transform it into a char* array, by assigning it to a string (easiest way imo)
            char salt_array[3] = {salt_possibilities[salt_one], salt_possibilities[salt_two], salt_possibilities[64]};
            string salt = salt_array;


            string my_hash = crypt(password, salt);

            // using strcmp because nothing else would work here properly. See strcmp documentation for more
            if (strcmp(hash, my_hash) == 0)
            {
                // If we find it we print the password and then return true, exiting
                printf("%s\n", password);
                return true;
            }

        }
    }
    return false;
}

