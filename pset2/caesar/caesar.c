//this will use Caesar's encrypting method, which changes the letter by k digits to the right of the alphabet.
#import <stdio.h>
#import <cs50.h>
#import <stdlib.h>
#import <string.h>
#import <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string k = argv[1];
        int kNumber = atoi(argv[1]);
        printf("%i \n", kNumber);
        string plain = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plain); i++)
        {
            if (isalpha(plain[i]))
            {
                int ascii = (plain[i]);
                if (isupper(plain[i]))
                {
                    int newUp = (ascii - 65 + kNumber) % 26;
                    char newUpper = newUp + 65;
                    printf("%c", newUpper);
                }
                else if (islower(plain[i]))
                {
                    int newLo = (ascii - 97 + kNumber) % 26;
                    char newLower = newLo + 97;
                    printf("%c", newLower);
                }
            }
            else
            {
                printf("%c", plain[i]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Error\n");
        return 1;
    }
}