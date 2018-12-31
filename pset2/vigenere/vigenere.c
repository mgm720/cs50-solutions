//this will use Vigenere's encryption method, changing the characters by an alphabetical key (the input) where a = 0 and z = 25
#import <stdio.h>
#import <cs50.h>
#import <stdlib.h>
#import <string.h>
#import <ctype.h>

int main(int argc, string argv[])
{
    //make sure command line argument is only 2 lines (./vigenere + key)
    if (argc != 2)
    {
        printf("Only one command line argument allowed\n");
        return 1;
    }
    //make sure all characters in the key are letters
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if(!isalpha(argv[1][i]))
            {
                printf("alphabetic characters only\n");
                return 1;
            }
        }
    }
        //get the key and find the length
        string key = argv[1];
        int keyLength = strlen(key);

        //get string for plaintext
        string plain = get_string("plaintext: ");

        //print ciphertext: before decoding
        printf("ciphertext: ");

        //this for loop is for the plain text input
        for (int i = 0, j = 0; i < strlen(plain); i++)
        {
            //create variable for key of each letter..use "toupper" to downcast any lowercase letters
            int newKey = toupper(key[j % keyLength]) - 65;

            if (isalpha(plain[i]))
            {
                int ascii = (plain[i]);

                //keeps the case of the characters in the if function
                if (isupper(plain[i]))
                {
                    int newUp = (ascii - 65 + newKey) % 26;
                    char newUpper = newUp + 65;
                    printf("%c", newUpper);
                }
                else if (islower(plain[i]))
                {
                    int newLo = (ascii - 97 + newKey) % 26;
                    char newLower = newLo + 97;
                    printf("%c", newLower);
                }
                //only do j++ if the character is a letter
                j++;
            }
            else
            {
                //do not modify other characters
                printf("%c", plain[i]);
            }
        }
        printf("\n");
    }

