#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // global variable
    int height;
    // do loop makes sure number is between 0 and 23
    do
    {
        height = get_int("Height:");
    } while (height < 0 || height > 23);

    //outermost loop contains all others and \n function is included at the bottom
    for(int newline = 0; newline < height; newline++)
    {
        //spaces loop makes spaces equal to the height minus the newline...spaces must be >1 or loop will go on forever
        for(int spaces = height - newline; spaces > 1; spaces--)
        {
            printf(" ");
        }
        //hashtag loop
        for(int hashtags = 0; hashtags < newline + 2; hashtags++)
        {
            printf("#");
        }
        printf("\n");
    }
}