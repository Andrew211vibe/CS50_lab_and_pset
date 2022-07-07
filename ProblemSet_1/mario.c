#include <cs50.h>
#include <stdio.h>

// less version
// int main(void) 
// {
//     const int MIN = 0, MAX = 100;
//     int n = 0;
//     // prompt for height
//     // printf("Height: ");
//     // scanf("%d", &n);
//     n = get_int("Height: ");
//     // for row
//     if (n >= MIN && n <= MAX)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             // for column whitespaces
//             for (int j = 0; j < n-i; j++)
//             {
//                 printf(" ");
//             }
//             // for column #
//             for (int k = 0; k < i; k++)
//             {
//                 printf("#");
//             }
//             // start a new row
//             printf("\n");
//         }
//     }
//     else
//     {
//         printf("input error");
//     }

//     return 0;
// }

// more version
int main(void) 
{
    const int MIN = 0, MAX = 100;
    void draw (int x, int y);
    int n = 0;
    // prompt for height
    // printf("Height: ");
    // scanf("%d", &n);
    n = get_int("Height: ");
    // for row
    if (n >= MIN && n <= MAX)
    {
        for (int i = 1; i <= n; i++)
        {
            draw(i, n);
            // start a new row
            printf("\n");
        }
    }
    else
    {
        printf("input error");
    }

    return 0;
}

void draw (int x, int y)
{
    void draw_spaces (int i, int j);
    void draw_hashes (int i);

    draw_spaces(x, y);
    draw_hashes(x);
    printf("  ");
    draw_hashes(x);

}

void draw_spaces (int i, int n)
{
    // for column whitespaces
    for (int j = 0; j < n-i; j++)
    {
        printf(" ");
    }
}

void draw_hashes (int i)
{
    // for column hashes
    for (int k = 0; k < i; k++)
    {
        printf("#");
    }
}