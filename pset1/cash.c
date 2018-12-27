#import <stdio.h>
#import <cs50.h>
#import <math.h>

int main(void)
{
    //global variables
    float change;
    //do loop makes sure number is positive
    do
    {
        change = get_float("Change owed:");
    }
    while (change < 0);
    //must convert change to integer and round it properly...import <math.h>
    int convertedChange = round(change * 100);

    int coinsNeeded = 0;
    for (int quarter = 25; (convertedChange / quarter) >= 1 ; convertedChange = convertedChange - quarter)
    {
        coinsNeeded++;
        //print statements used to check for progress and correctness.
        printf("used %d coins so far\n", coinsNeeded);
    }
    for (int dime = 10; (convertedChange / dime) >= 1 ; convertedChange = convertedChange - dime)
    {
        coinsNeeded++;
        printf("used %d coins so far\n", coinsNeeded);
    }
    for (int nickel = 5; (convertedChange / nickel) >= 1 ; convertedChange = convertedChange - nickel)
    {
        coinsNeeded++;
        printf("used %d coins so far\n", coinsNeeded);
    }
    for (int penny = 1; (convertedChange / penny) >= 1 ; convertedChange = convertedChange - penny)
    {
        coinsNeeded++;
        printf("used %d coins so far\n", coinsNeeded);
    }
    printf("%d\n", coinsNeeded);
}