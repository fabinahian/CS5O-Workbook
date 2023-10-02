// Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter b kth positions.

// More formally, if p is some plaintext (i.e., an unencrypted message), p_i is the ith character in p, and
// k is a secret key (i.e., a non-negative integer), then each letter, c_i, in the ciphertext,c, is computed as

// c_i = (p_i + k) % 26

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string argv);
void rotate(char c, int k);

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2 || only_digits(argv[1]) > 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");

    int size = strlen(plaintext);

    printf("ciphertext: ");

    for (int i = 0; i < size; i++)
    {
        rotate(plaintext[i], key);
    }
    printf("\n");
}

bool only_digits(string argv)
{
    int len = strlen(argv);
    int sum = 0;

    for (int j = 0; j < len; j++)
    {
        if (isdigit(argv[j]))
        {
            sum = sum + 0;
        }
        else
        {
            sum++;
        }
    }
    return sum;
}

void rotate(char c, int k)
{
    if (islower(c))
    {
        if (c + k > 'z')
        {
            printf("%c", (c - 'a' + k) % 26 + 'a');
        }
        else
        {
            printf("%c", c + k);
        }
    }

    else if (isupper(c))
    {
        if (c + k > 'Z')
        {
            printf("%c", (c - 'A' + k) % 26 + 'A');
        }
        else
        {
            printf("%c", c + k);
        }
    }

    else
    {
        printf("%c", c);
    }
}
