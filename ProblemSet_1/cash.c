#include <stdio.h>
// #include <cs50.h>

const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

int main(void)
{
    int get_cent(void);
    int calculate_quarter(int x);
    int calculate_dime(int x);
    int calculate_nickel(int x);
    int calculate_penny(int x);
    int changes;
    int num_q=0, num_d=0, num_n=0, num_p=0;
    // prompt for changes
    changes = get_cent();
    // calculate
    if (changes >= QUARTER)
    {
        num_q = calculate_quarter(changes);
        changes -= num_q * QUARTER;
    }
    if (changes >= DIME)
    {
        num_d = calculate_dime(changes);
        changes -= num_d * DIME;
    }
    if (changes >= NICKEL)
    {
        num_n = calculate_nickel(changes);
        changes -= num_n * NICKEL;
    }
    if (changes >= PENNY)
    {
        num_p = calculate_penny(changes);
        changes -= num_p * PENNY;
    }

    printf("%d quarters, %d dimes, %d nickels, %d pennies\n", num_q, num_d, num_n, num_p);
    
    return 0;
}

int get_cent(void)
{
    int money = 0;
    do
    {
        printf("Changes: ");
        scanf("%d", &money);
        // money = get_int("Changes: ");
    } while (money < 0);
    return money;
}

int calculate_quarter(int x)
{
    int num_quarter = 0;
    return num_quarter = x / QUARTER;
}

int calculate_dime(int x)
{
    int num_dime = 0;
    return num_dime = x / DIME;
}

int calculate_nickel(int x)
{
    int num_nickel = 0;
    return num_nickel = x / NICKEL;
}

int calculate_penny(int x)
{
    int num_penny = 0;
    return num_penny = x / PENNY;
}