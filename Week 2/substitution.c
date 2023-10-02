#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string substitute(string text, string argv);

int main(int argc, string argv[])
{
    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int len = strlen(argv[1]);

    if (len > 26 || len < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (!isalpha(argv[1][j]))
            {
                printf("Invalid Character Found: %c.\n", argv[1][j]); //when alphabets are allowed
                return 1;
            }

            if (i == j)
            {
                continue;
            }
            else
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Key must NOT contain duplicate characters.\n"); //an alphabet cannot be repeated
                    return 1;
                }
            }
        }
    }

    string text = get_string("plaintext:  ");
    printf("ciphertext: %s", substitute(text, argv[1]));
    printf("\n");
    return 0;
}

string substitute(string text, string argv)
{
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            if(isupper(text[i]))
            {
                text[i] = toupper(argv[text[i] - 'A']); // text[i] - 'A' = 0 and argv[0] is the first element of the key.

            }

            else //islower
            {
                 text[i] = tolower(argv[text[i] - 'a']);
                 // abc with a key: efghijklmnopqrstuvyxyzabcd, gets the following result:
                // abc --> efg because
                // char (a) - char (a) = 0; and 0th position of the key is e. so, a -- > e
            }
        }

        else
        {
            text[i] = text[i];
        }
    }

    return text;
}