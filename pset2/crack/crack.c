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
    if (argc != 2)
    {
        printf("Please use a password hash as argument!\n");
        return 1;
    }
    hash = argv[1];
    printf("cracking %s\n", hash);

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

    return 1;
}

bool crack_one_letter_password()
{
    printf("starting with one_letter_passwords\n");

    for (int i = 0; i < 52; i++)
    {
        char password_array[2] = {key_possibilities[i], key_possibilities[52]};
        string password = password_array;
        if(crack_password(password))
        {
            return true;
        }
    }
    return false;
}

bool crack_two_letter_password()
{
    printf("cracking two letters\n");

    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            char password_array[3] = {key_possibilities[i], key_possibilities[j], key_possibilities[52]};
            string password = password_array;
            if(crack_password(password))
            {
                return true;
            }
        }
    }
    return false;
}

bool crack_three_letter_password()
{
    printf("What about three??\n");

    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                char password_array[4] = {key_possibilities[i], key_possibilities[j], key_possibilities[k], key_possibilities[52]};
                string password = password_array;
                if(crack_password(password))
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
    for (int i = 0; i < 52; i++)
    {
        printf("cracking %cxxx\n", key_possibilities[i]);
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                for (int l = 0; l < 52; l++)
                {
                    char password_array[5] = {key_possibilities[i], key_possibilities[j], key_possibilities[k], key_possibilities[l], key_possibilities[52]};
                    string password = password_array;
                    if(crack_password(password))
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
                        char password_array[6] = {key_possibilities[i], key_possibilities[j], key_possibilities[k], key_possibilities[l], key_possibilities[m], key_possibilities[52]};
                        string password = password_array;
                        if(crack_password(password))
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



bool crack_password(string password)
{
    printf("trying %s\n", password);
    for (int salt_one = 0; salt_one < 64; salt_one++)
    {
        for (int salt_two = 0; salt_two < 64; salt_two++)
        {
            char salt_array[3] = {salt_possibilities[salt_one], salt_possibilities[salt_two], salt_possibilities[64]};
            string salt = salt_array;

            string my_hash = crypt(password, salt);


            if(strcmp(hash, my_hash) == 0)
            {
                printf("%s\n", password);
                return true;
            }

        }
    }
    return false;
}

