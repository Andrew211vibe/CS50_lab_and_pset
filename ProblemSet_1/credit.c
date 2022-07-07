#include <stdio.h>

int main(void)
{
    unsigned long long card_number;
    int sum;
    int calc(long long card_number);

    printf("Input card number: ");
    scanf("%lld", &card_number);

    sum = calc(card_number);

    if (sum % 10 == 0)
    {
        if (card_number / 10000000000000 == 4 || card_number / 1000000000000000 == 4 || card_number / 10000000000000000 == 4)
        {
            printf("VISA\n");
        }
        else if (card_number / 10000000000000 == 34 || card_number / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        else if (card_number / 100000000000000 == 51 || card_number / 100000000000000 == 52 || card_number / 100000000000000 == 53 ||   card_number / 100000000000000 == 54 || card_number / 100000000000000 == 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("CAN'T RECOGNIZE\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

int calc(long long card_number)
{
    int x_sum = 0, y_sum = 0;
    int digit;
    // calculate sum of second-to-last digit
    for (unsigned long long i = card_number; i > 0; i /= 10)
    {
        i /= 10;
        digit = i % 10;
        if (digit * 2 >= 10)
        {
            x_sum += digit * 2 / 10 + digit * 2 % 10;
        }
        else
        {
            x_sum += digit * 2;
        }
    }
    // calculate sum of other digits
    for (unsigned long long j = card_number; j > 0; j /= 10)
    {
        digit = j % 10;
        j /= 10;
        y_sum += digit;
    }
    return x_sum + y_sum;
}