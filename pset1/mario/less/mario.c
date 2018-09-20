#include <stdio.h>

//As I am writing this code ahead of watching the lecture, I am using https://www.tutorialspoint.com/cprogramming to help me
//with input methods and type conversion

int main(void)
{

    while (1)
    {

        int startValue = -1;
        int *input = &startValue;
        //This input is the easiest way I found it to be done, will see if this is how they want us to do it after the lecture (I don't think so)

        //Leaving loop when the value is permitted
        while ((*input < 0) || (*input > 23))
        {
            printf("\nHeight: ");
            scanf("%d", input);
        }

        //entering print loop
        for (int i = 0; i < *input; i++)
        {
            //printing empty space
            for (int j = 0; (j < (*input - 1 - i)); j++)
            {
                printf(" ");
            }

            //printing blocks
            for (int j = 0; j < i + 2; j++)
            {
                printf("#");
            }

            printf("\n");
        }

        break;
    }

}


