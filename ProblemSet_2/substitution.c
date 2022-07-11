#include <stdio.h>
#include <string.h>
#include <ctype.h>
// #include <cs50.h>

const char STANDARD[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
void encrypt(char alpha_upper[27], char b[100]);

int main(int argc, char *argv[])
{
    char alpha_upper[27];
    // string plain;
    char plain[100];
    // char alpha[27] = {"YTNSHKVEFXRBAUQZCLWDMIPGJO"};
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) == 26)
    {
        // length of the argv[1]
        int n = strlen(argv[1]);

        // convert to upper case into alpha
        for (int z = 0; z < n; z++)
        {
            alpha_upper[z] = toupper(argv[1][z]);
        }

        // check if every alphabet is in
        for (int i = 0; i < n; i++)
        {
            // count for not
            int count = 0;

            for (int j = 0; j < n; j++)
            {
                // check whether is alpha
                if (isalpha(alpha_upper[j]) == 0)
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
                if (STANDARD[i] == alpha_upper[j])
                {
                    count++;
                }
            }
            if (count != 1)
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
        printf("Plain text: ");
        gets(plain);
        // plain = get_string("plaintext: ");
    }
    // chech if have 26 characters
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // run encrypt
    encrypt(alpha_upper, plain);
    return 0;
}

void encrypt(char alpha_upper[27], char b[100])
{
    int n = strlen(b);
    char alpha_lower[27];
    // convert to lower case
    for (int i = 0; i < 26; i++)
    {
        alpha_lower[i] = tolower(alpha_upper[i]);
    }

    // encrypt
    for (int i = 0; i < n; i++)
    {
        if (islower(b[i]))
        {
            b[i] = alpha_lower[b[i] - 97];
        }
        else if (isupper(b[i]))
        {
            b[i] = alpha_upper[b[i] - 65];
        }
    }

    printf("ciphertext: %s\n", b);
}