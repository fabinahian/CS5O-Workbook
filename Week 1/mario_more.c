//adjacent pyramids

#include <cs50.h>
#include <stdio.h>

void build_adjacent_pyramids(int);

int main(void)
{
    // Prompts the user for height (between 1 and 8)

    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    build_adjacent_pyramids(n);
}

void build_adjacent_pyramids(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }

        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }

        printf("\n");
    }
}
