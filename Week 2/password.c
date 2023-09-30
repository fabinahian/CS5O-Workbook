// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

// Your function will iterate through the password that’s supplied to it as an argument.
// Since you have to find at least one lower case letter, one upper case letter, one number and one symbol,
// you may want to create a boolean variable for each and set each to false before you iterate through the string.
// If you then find a number, for instance you can set that boolean to true.
// If all booleans are true at the end of the function, it means all criteria are met, and you would return true.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int len = strlen(password);

    int is_lower = 0, is_upper = 0, is_digit = 0, is_symbol = 0;

    for (int i = 0; i < len; i++)
    {
        is_upper = is_upper + isupper(password[i]);
        is_lower = is_lower + islower(password[i]);
        is_digit = is_digit + isdigit(password[i]);
        is_symbol = is_symbol + ispunct(password[i]);
    }
    return (is_upper && is_lower && is_digit && is_symbol);
}
