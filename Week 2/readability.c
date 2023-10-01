#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letter_count(string text);
int word_count(string text);
int sentence_count(string text);

int main(void)
{
    string text = get_string("Enter your text:\n");

    int letters = letter_count(text);
    int words = word_count(text);
    int sentences = sentence_count(text);

    // index = 0.0588 * L - 0.296 * S - 15.8
    // where L is the average number of letters per 100 words in the text,
    // and S is the average number of sentences per 100 words in the text.

    float index = round(0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %i\n", (int) index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int letter_count(string text)
{
    int len = strlen(text);
    int letters = 0;

    for (int i = 0; i < len; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters = letters + 1;
        }
    }
    return letters;
}

int word_count(string text)
{
    int len = strlen(text);
    int words = 0;

    for (int j = 0; j < len; j++)
    {
        if (text[j] == ' ')
        {
            words = words + 1;
        }
    }
    words++;
    return words;
}

int sentence_count(string text)
{
    int len = strlen(text);
    int sentences = 0;

    for (int k = 0; k < len; k++)
    {
        if (text[k] == '.' || text[k] == '?' || text[k] == '!')
        {
            sentences++;
        }
    }

    return sentences;
}