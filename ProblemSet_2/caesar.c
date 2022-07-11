#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include <cs50.h>

const int ALPHA = 26;
void encrypt(char input[100], int k);
// void encrypt(string input, int k);

int main(int argc, char *argv[])
{
    int k;
    // int k = 13;
    char plain[100];
    // string plain;
    if (argc == 2 && atoi(argv[1]) > 0)
    // if (k > 0)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        k = strtol(argv[1], NULL, 10);
        printf("Plain text: ");
        gets(plain);
        // plain = get_string("Plain text: ");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    encrypt(plain, k);
    return 0;
}

void encrypt(char input[100], int k)
// void encrypt(string input, int k)
{
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]))
        {
            int c = (int)input[i];
            int res = 0;
            // k % 26 to eliminate rounds
            res = c + k % ALPHA;
            if (islower(input[i]))
            {
                // res > 122 to return to 97
                res -= (res > 122) ? ALPHA : 0;
            }
            else if (isupper(input[i]))
            {
                // res > 90 to return to 65
                res -= (res > 90) ? ALPHA : 0;
            }
            input[i] = (char)res;
        }
    }
    printf("ciphertext: %s\n", input);
}