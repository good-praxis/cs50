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
    // in this case we want a two space-gap between two "blocks"-sized rows of blocks
    for (int i = 0; i < input; i++)
    {
        int spaces = input - i - 1;
        int blocks = i + 1;
        print_spaces(spaces);
        print_blocks(blocks);
        print_spaces(2);
        print_blocks(blocks);
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