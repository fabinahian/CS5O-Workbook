#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }
    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int len = strlen(input);

    if (input[0] == '\0')
    {
        return 0;
    }

    else
    {
        int n = (int) input[len - 1];
        input[len - 1] = '\0';

        return n + 10 * convert(input) - '0';
    }
}