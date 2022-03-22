#include <cs50.h>
#include <stdio.h>

int main(void)
{

//Defines global variables.
    int check = 0;
    int n = 0;

//Checks that height is between 1 and 8 and reprompts if its not.
    do
    {

    int height = get_int("Height: ");

    if (height > 0 & height <= 8)
    {
        check++;
        n = height;
    }
    }
    while (check == 0);

//Iterates printing increasing number of blocks until their are layers equal to height.
        for (int i = 0; i < n; i++)
        {
//Defines the number of spaces and blocks in the image.
            int left_blocks = 0;
            int spaces = n - 2;
            int right_blocks = 0;

            while (spaces >= i)
            {
                printf(" ");
                spaces--;
            }

            while (left_blocks <= i)
            {
                printf("#");
                left_blocks++;
            }

            printf("%*s", 2, "");

            while (right_blocks <= i)
            {
                printf("#");
                right_blocks++;

            }
            printf("\n");
        }
}
