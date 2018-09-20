#include <stdio.h>
#include <cs50.h>


int main(void)
{
    // initilization
    int get_valid_input(void);
    void print_spaces(int);
    void print_blocks(int);

    int input = get_valid_input();

    // This iterates through every line
    for (int i = 0; i < input; i++)
    {
        print_spaces(input - i - 1);
        print_blocks(i + 2);
        printf("\n");
    }
}

// Gets an input that is and int between 0 and 23
int get_valid_input(void)
{
    while (true)
    {
        int input = get_int("Height: ");
        if (input >= 0 && input < 24)
        {
            return input;
        }
    }
}

// prints numberOfSpaces amount of spaces
void print_spaces(int numberOfSpaces)
{
    for (int i = 0; i < numberOfSpaces; i++)
    {
        printf(" ");
    }
    return;
}

// prints numberOfBlocks amount of blocks (#)
void print_blocks(int numberOfBlocks)
{
    for (int i = 0; i < numberOfBlocks; i++)
    {
        printf("#");
    }
    return;
}


