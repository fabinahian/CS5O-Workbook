// Most cards use an algorithm invented by Hans Peter Luhn of IBM. 
// According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

// Multiply every other digit by 2 starting with the number’s second-to-last digit, 
// and then add those PRODUCTS' DIGITS together. Add the sum to the sum of the digits that weren’t multiplied by 2.
// If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

#include <cs50.h>
#include <stdio.h>

int check_validity(long);

int main(void)
{
    long number = get_long("Input your card number: ");  // User input

    long temp = 0; // Variables

    const long original = number; // Keeping the card number safely stored

    // Handling a 13-digit input
    // Visa uses 13-digit numbers & numbers start with 4

    if ((original >= 1000000000000 && original < 10000000000000))
    {
        temp = check_validity(number);

        if (temp == 1)
        {
            if ((original / 1000000000000 == 4))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

    }

    // Handling a 15-digit input
    // American Express uses 15-digit numbers & start with 34 or 37

    else if (original >= 100000000000000 && original < 1000000000000000)
    {
        temp = check_validity(number);

        if (temp == 1)

        {
            if ((original / 10000000000000 == 34 || original / 10000000000000 == 37))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }


    }

    // Handling a 16-digit input
    else // (original >= 1000000000000000 && original < 10000000000000000)
    {
        temp = check_validity(number);

        if (temp == 1)

        {
            if ((original / 1000000000000000 == 4))
            {
                printf("VISA\n");
            }
            else if (original / 100000000000000 == 51 || original / 100000000000000 == 52 || original / 100000000000000 == 53
                     || original / 100000000000000 == 54 || original / 100000000000000 == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

int check_validity(long card)
{
    long temp = 0,  normal = 0, multiplied = 0, total = 0, last = 0, second_last = 0, vault = 0;
    const long original = card;

    if (original >= 1000000000000 && original < 10000000000000) // 13-digit
    {
        for (int i = 1; i <= 13; i++)
        {
            normal = normal + (card % 10);  // 2164 % 10 = 4
            card = card / 10; // 2164 / 10 = 216

            if (((card % 10) * 2) > 9)     // 6 * 2 = 12 > 9
            {
                vault = ((card % 10) * 2);  // 12
                last = vault % 10;          // 12 % 10 = 2
                second_last = vault / 10;   // 12 / 10 = 1

                multiplied = multiplied + last + second_last;
                vault = 0; // resetting variable
            }
            else
            {
                multiplied = multiplied + ((card % 10) * 2);
            }

            card = card / 10;
        }

        if ((normal + multiplied) % 10 == 0)
        {
            temp = 1;
            return temp;
        }
        else
        {
            temp = 0;
            return temp;
        }

    }

    else if (original >= 100000000000000 && original < 1000000000000000) // 15-digit
    {
        for (int i = 1; i <= 15; i++)
        {
            normal = normal + (card % 10);  // 2164 % 10 = 4
            card = card / 10; // 2164 / 10 = 216

            if (((card % 10) * 2) > 9)      // 6 * 2 = 12 > 9
            {
                vault = ((card % 10) * 2);  // 12
                last = vault % 10;          // 12 % 10 = 2
                second_last = vault / 10;   // 12 / 10 = 1

                multiplied = multiplied + last + second_last;
                vault = 0; // resetting variable
            }
            else
            {
                multiplied = multiplied + ((card % 10) * 2);
            }

            card = card / 10;
        }

        if ((normal + multiplied) % 10 == 0)
        {
            temp = 1;
            return temp;
        }
        else
        {
            temp = 0;
            return temp;
        }

    }

    else if (original >= 1000000000000000 && original < 10000000000000000) // 16-digit
    {
        for (int i = 1; i <= 16; i++)
        {
            normal = normal + (card % 10);  // 2164 % 10 = 4
            card = card / 10; // 2164 / 10 = 216

            if (((card % 10) * 2) > 9)      // 6 * 2 = 12 > 9
            {
                vault = ((card % 10) * 2);  // 12
                last = vault % 10;          // 12 % 10 = 2
                second_last = vault / 10;   // 12 / 10 = 1

                multiplied = multiplied + last + second_last;
                vault = 0; // resetting variable
            }
            else
            {
                multiplied = multiplied + ((card % 10) * 2);
            }

            card = card / 10;
        }

        if ((normal + multiplied) % 10 == 0)
        {
            temp = 1;
            return temp;
        }
        else
        {
            temp = 0;
            return temp;
        }
    }
    else
    {
        temp = 0;
        return temp;
    }
}
