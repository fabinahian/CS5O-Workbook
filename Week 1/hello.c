#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("hello, world\n");

    //Asks for user's name
    string name = get_string("What's your name? ");

    //Uses the input
    printf("hello, %s\n", name);
}