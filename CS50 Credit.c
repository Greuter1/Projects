#include <cs50.h>
#include <stdio.h>

int main(void)
{

//Defines global variables
    int digit;
    int test_digit;
    int digit_count = 0;
    int test_digit_count = 0;
    int first_digit;
    int second_digit;
    int first_digits;
    int odd_digit_sum_product = 0;
    int even_digit_sum = 0;
    int remainder;

    //Prompts user for a credit card number
    long credit = get_long("Number: ");
    long test_credit = credit;

    do
    {
        //Defines rules for manipulating the variables
        test_digit = test_credit % 10;
        test_credit /= 10;
        test_digit_count++;
    }
    while (test_credit != 0);

    //Algorithm iterates through each digit of the credit card number performing some operations
    do
    {
        //Defines rules for manipulating the variables
        digit = credit % 10;
        credit /= 10;
        digit_count++;
        if (test_digit_count % 2 == 0)
        {
            if (digit_count % 2 == 0)
            {
                if(digit * 2 >= 10)
                {
                    odd_digit_sum_product += (digit * 2) % 10;
                    odd_digit_sum_product += 1;
                }
                else
                {
                odd_digit_sum_product += digit * 2;
                }
            }
            else
            {
                even_digit_sum += digit;
            }
        }
        else
        {
            if (digit_count % 2 == 0)
            {
                if(digit * 2 >= 10)
                {
                    odd_digit_sum_product += (digit * 2) % 10;
                    odd_digit_sum_product += 1;
                }
                else
                {
                odd_digit_sum_product += digit * 2;
                }
            }
            else
            {
                even_digit_sum += digit;
            }
        }
        //Finds the second digit after iteration is complete
        if (digit_count >= 1)
        {
            second_digit = first_digit;
        }
        //Finds the first digit after iteration is complete
        first_digit = digit;
    }
    while (credit != 0);

    //Defines a variable for the first two digits
    first_digits = (first_digit * 10) + second_digit;

    //Defines the remainder of the sum product algorithm
    remainder = (odd_digit_sum_product + even_digit_sum) % 10;

    //Determines if the card is valid and if it is what company it belongs to
    if (remainder == 0)
    {
        if (first_digits >= 51 & first_digits <= 55 & digit_count == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (digit_count == 13 || digit_count == 16)
            {
                if (first_digit == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if (first_digits == 34 || first_digits == 37 & digit_count == 15)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
    }
    else
    {
        printf("INVALID\n");
    }
}
