// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

// This function will change the following vowels to numbers:
// a becomes 6, e becomes 3, i becomes 1, o becomes 0 and u does not change.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Invalid Command!");
        return 1;
    }

    else
    {
        printf("%s\n", replace(argv[1]));
    }
}

string replace(string word)
{
    int size = strlen(word);

    for (int j = 0; j < size; j++)
    {
        if (word[j] == 'a' || word[j] == 'A')
        {
            word[j] = '6';
        }
        else if (word[j] == 'e' || word[j] == 'E')
        {
            word[j] = '3';
        }
        else if (word[j] == 'i' || word[j] == 'I')
        {
            word[j] = '1';
        }
        else if (word[j] == 'o' || word[j] == 'O')
        {
            word[j] = '0';
        }
        else if (word[j] == 'u' || word[j] == 'U')
        {
            word[j] = word[j];
        }
        else
        {
            word[j] = word[j];
        }
    }

    return word;
}