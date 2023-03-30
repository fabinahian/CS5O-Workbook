// Background
// Prime numbers are defined as whole numbers greater than 1, 
// whose only factors are 1 and itself. So 3 is prime because its only factors are 1 and 3, 
// while 4 is composite and not prime, because it is the product of 2 × 2. 
// In this lab you will write an algorithm to generate all prime numbers in a range specified by the user.

#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO

    for (int j=2; j<= (number/2); j++)
    {
        if (number%j==0)
        return false;
    }
    return true;
}
