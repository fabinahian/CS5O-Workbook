
//right-aligned pyramid

#include <cs50.h>
#include <stdio.h>

void build_right_aligned_pyramid(int);

int main(void)
{
    // Prompts the user for height (between 1 and 8)

    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    build_right_aligned_pyramid(n);
}

void build_right_aligned_pyramid(int height)
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

        printf("\n");
    }

}
