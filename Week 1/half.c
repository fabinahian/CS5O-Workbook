//Background
//Suppose you are eating out at a restaurant with a friend and want to split the bill evenly. 
//You may want to anticipate the amount you’ll owe before the bill arrives with tax added. 
//In this problem, you’ll complete a function to calculate the amount each of you owes based on the bill amount, the tax, and the tip.

// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half (bill_amount, tax_percent, tip_percent) );
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    float my_share, total, tax_amount, tip_amount;

    tax_amount = bill * (tax / 100.0);
    tip_amount = ( bill + tax_amount) * (tip / 100.0);

    total = bill + tax_amount + tip_amount;

    my_share = total / 2.0;

    return my_share;
}
