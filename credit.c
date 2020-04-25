#include<cs50.h>
#include<stdio.h>

int main(void)
{
    // Add variable cardNumber outside of do while loop for further usage
    long cardNumber;

    // Ask for correct input
    do
    {
        cardNumber = get_long("Number: ");
    }
    while (cardNumber < 0);

    // Add variable totalNumber, which means the count of card number, ex. 4044 -> 4, 55667 -> 5. It's not named beautifully or clearly enought though.
    int totalNumber = 0;
    // Add a variable cardNumberForCalculation for cardNumber for further calculation, in order not to clear out original value cardNumber.
    long cardNumberForCalculation = cardNumber;

    // Calculate the totalNumber by new added variable cardNumberForCalculation
    while (cardNumberForCalculation > 0)
    {
        cardNumberForCalculation /= 10;
        totalNumber++;
    }

    //  Make sure the count of cardNumber is between 13 and 16, or else it's invalid.
    if (totalNumber < 13 || totalNumber > 16)
    {
        printf("INVALID\n");
        // return 0 is introduced in week 2.
        // At the beginning of the code "int main(void)", we can return Int here, and as I recalled it won't continue running the codes afterwards.
        // In other world, it exit here.
        return 0;
    }


    // Sorry about the dirty code. It starts to get messy here.
    // d0 ~ d15, d0 means digit 0, which is the 'left' side of the card number. d15 is the 'right' side of the card number.
    // ex. 4003600000000014, d0 = 4, d1 = 1, ... , d14 = 0, d15 = 4

    // Calculate the cardNumber underline part.
    int d1 = (cardNumber % 100) / 10;
    int d3 = (cardNumber % 10000) / 1000;
    int d5 = (cardNumber % 1000000) / 100000;
    int d7 = (cardNumber % 100000000) / 10000000;
    int d9 = (cardNumber % 10000000000) / 1000000000;
    int d11 = (cardNumber % 1000000000000) / 100000000000;
    int d13 = (cardNumber % 100000000000000) / 10000000000000;
    int d15 = (cardNumber % 10000000000000000) / 1000000000000000;

    // This is kind of tricky here. I used the 'ternary operation'. You can google it.
    // There are two parts you need to know here.
    // 1. Ternary Operation(tricky but clean and comfortable after knowing)
    // 2. Convertion between "11 -> 1+1, 12 -> 1+2, ... , 18 -> 1+8" and "originalNumber * 2" (where the description at the left told us to do)
    // First of all, I'll start from ternary:
    // Ex. below "int d1SingleDigit = (d1 < 5) ? d1*2 : (1+2*(d1-5));" -> meaning if d1 < 5, do (d1*2), else do (1+2*(d1-5))
    // Secondly, convertion between (5 * 2 -> 10 -> 1+0 -> 1) so 5 -> 1 etc.
    // In conclusion, 5 -> 1, 6 -> 3, 7 -> 5, 8 -> 7, 9 -> 9, a little bit of math here make it more elegant.
    int d1SingleDigit = d1 < 5 ? d1*2 : (1+2*(d1-5));
    int d3SingleDigit = d3 < 5 ? d3*2 : (1+2*(d3-5));
    int d5SingleDigit = d5 < 5 ? d5*2 : (1+2*(d5-5));
    int d7SingleDigit = d7 < 5 ? d7*2 : (1+2*(d7-5));
    int d9SingleDigit = d9 < 5 ? d9*2 : (1+2*(d9-5));
    int d11SingleDigit = d11 < 5 ? d11*2 : (1+2*(d11-5));
    int d13SingleDigit = d13 < 5 ? d13*2 : (1+2*(d13-5));
    int d15SingleDigit = d15 < 5 ? d15*2 : (1+2*(d15-5));

    // Add totalOfDigitEven variable to sum all the underline value by the rule.
    // To be honest, it's poorly named... You can name it another way. This was just the exact same code I copied from my CS50 pset1.
    int totalOfDigitEven = d1SingleDigit + d3SingleDigit + d5SingleDigit + d7SingleDigit + d9SingleDigit + d11SingleDigit + d13SingleDigit + d15SingleDigit;

    // Calculate the cardNumber not underline part.
    int d0 = (cardNumber % 10) / 1;
    int d2 = (cardNumber % 1000) / 100;
    int d4 = (cardNumber % 100000) / 10000;
    int d6 = (cardNumber % 10000000) / 1000000;
    int d8 = (cardNumber % 1000000000) / 100000000;
    int d10 = (cardNumber % 100000000000) / 10000000000;
    int d12 = (cardNumber % 10000000000000) / 1000000000000;
    int d14 = (cardNumber % 1000000000000000) / 100000000000000;

    // Add totalOfAll variable meaning the underline and not underline part by the rule.
    int totalOfAll = totalOfDigitEven + d0 + d2 + d4 + d6 + d8 + d10 + d12 + d14;

    // Print out some values for debug... Struggling for long time. Lots of zeros up there omg.
    /*
    printf("%i %i %i %i %i %i %i %i \n", d0, d1, d2, d3, d4, d5, d6, d7);
    printf("%i %i %i %i %i %i %i %i \n",  d8, d9, d10, d11, d12, d13, d14, d15);
    printf("%i %i \n", totalOfDigitEven,totalOfAll);
    */

    // Add firstDigit, secondDigit, meaning the left two number. ex. 4003600000000014 -> firstDigit = 4, secondDigit = 0
    int firstDigit, secondDigit = 0;
    // Calculate if countNumber is 16, 15, 13.
    if (totalNumber == 16)
    {
        firstDigit = d15;
        secondDigit = d14;
    } else if (totalNumber == 15)
    {
        firstDigit = d14;
        secondDigit = d13;
    } else if (totalNumber == 13)
    {
        firstDigit = d12;
        secondDigit = d11;
    }

    // Add final operator, if totalOfAll is divided by 10.
    if (totalOfAll % 10 == 0) {
        // Sum up firstDigit and secondDigit
        int sumOfFirstTwoDigit = firstDigit*10 + secondDigit;

        // Print for debug.
        /*
        printf("%i %i \n", firstDigit, secondDigit);
        printf("%i\n", sumOfFirstTwoDigit);
        */

        // If valid cardNumber, check what kind of card.
        if (sumOfFirstTwoDigit == 34 || sumOfFirstTwoDigit == 37)
        {
            printf("AMEX\n");
        } else if ((sumOfFirstTwoDigit >= 51 && sumOfFirstTwoDigit <= 55) || sumOfFirstTwoDigit == 22)
        {
            printf("MASTERCARD\n");
        } else if (firstDigit == 4)
        {
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }

    } else {
        printf("INVALID\n");
    }


}