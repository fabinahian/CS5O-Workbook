#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n, end, year = 0;
    // TODO: Prompt for start size
    do
    {
        n = get_long("Start size: ");
    }
    while (n < 9);
    // TODO: Prompt for end size
    do
    {
        end = get_long("End size: ");
    }
    while (end < n);
    // TODO: Calculate number of years until we reach threshold
    while (n < end)
    {
        n = n + (n / 3) - (n / 4);
        year = year + 1;
    }

    // TODO: Print number of years

    printf("Years: %li\n", year);
}
