#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Add variable dollars outside of do while loop for further usage
    float dollars;

    // Ask for correct input
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars<0);

    // Add cents calculate from dollars with math.h's round method
    int cents = round(dollars * 100);
    printf("%i\n", cents);

    // Add variables for count(answer we want to print out), and the values of quarters/dimes/nikels/pennis
    int count = 0, quarters = 25, dimes = 10, nikels = 5, pennies = 1;

    // Add do-while loop to calculate and update cents, until it's less than zero, get out of loop and go to the bottom printf
    do
    {
        if (cents >= quarters) {
            count += cents / quarters;
            cents %= quarters;
        }
        if (cents >= dimes) {
            count += cents / dimes;
            cents %= dimes;
        }
        if (cents >= nikels) {
            count += cents / nikels;
            cents %= nikels;
        }
        if (cents >= pennies){
            count += cents / pennies;
            cents %= pennies;
        }

    }
    while(cents < 0);

    // Print out final solution, how many coins
    printf("%i\n", count);
}