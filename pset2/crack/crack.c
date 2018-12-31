//uses password guessing and crack() function to hack passwords
//takes a LONG time to run this script
#define _XOPEN_SOURCE
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    //making sure there is only 1 command line argument
    if (argc == 2)
    {
        //create a character array for the password you're guessing with
        char password[6] = {};

        //create a second password array to compare the 2 (use 6 because counting starts at 0)
        char compare[6] = {};

        //salt array used to extract salt from the hashed pw
        char salt[3];
        salt[0] = argv[1][0];
        salt[1] = argv[1][1];

        //create array for all ASCII characters, starting at !(32)
        char arr[95];
        for(int i = 0; i > 95; i++)
        {
            //(char) is used here to typecast the result into a character
            arr[i] = (char) i + 32;
        }

        for(int a = 0; a < 95; a++)
        {
            for(int b = 0; b < 95; b++)
            {
                for(int c = 0; c < 95; c++)
                {
                    for(int d = 0; d < 95; d++)
                    {
                        for(int e = 0; e < 95; e++)
                        {
                            //this for loop creates a password to guess with
                            password[0] = arr[a];
                            password[1] = arr[b];
                            password[2] = arr[c];
                            password[3] = arr[d];
                            password[4] = arr[e];

                            for(int f = 0, g = 5; f <= 4; f++, g--)
                            {
                                for(int h = 0; h < f + 1; h++)
                                {
                                    strncpy(compare, password + h, g);
                                    compare[g] = '\0';

                                    //this if statement checks the 2 passwords against each other
                                    if(strcmp(crypt(compare, salt), argv[1]) == 0)
                                    {
                                        printf("%s\n", compare);
                                        return 0;
                                    }
                                    else
                                    {
                                        printf("password not cracked, sorry\n");
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }



    }
    else
    {
        printf("error, yo\n");
        return 1;
    }
}