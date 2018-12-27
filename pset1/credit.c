#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int sum;

    long long int cardNumber;
    do
    {
        cardNumber = get_long_long("Number: ");
    }
    while (cardNumber < 0);

    int numberOfDigits = floor (log10 (llabs (cardNumber))) + 1;
    int firstNumbers = cardNumber/pow(10, numberOfDigits-2);
    int veryFirstNumber = cardNumber/pow(10, numberOfDigits-1);

    for (long long int x = cardNumber ; x > 1; x = x/100)
    {
        int a;
        int y = x % 10;
        int z = (x/10) % 10;
        if (z*2 >= 10)
        {
            a = (z*2)%10 + (z*2)/10%10;
        }
        else
        {
            a = z*2;
        }
        sum = sum + y + a;
    }

    if (numberOfDigits < 13 || numberOfDigits > 16 || sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (firstNumbers > 50 && firstNumbers < 56 && numberOfDigits == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((firstNumbers == 34 || firstNumbers == 37) && numberOfDigits == 15)
    {
        printf("AMEX\n");
    }
    else if (veryFirstNumber == 4 && (numberOfDigits == 16 || numberOfDigits == 13))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}