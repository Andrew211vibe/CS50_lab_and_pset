#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
// #include <cs50.h>

// int cl_index_calc(string text);
int cl_index_calc(char input[255]);
// int count_letters(string text);
int count_letters(char input[255]);
// int count_words(string text);
int count_words(char input[255]);
// int count_sentences(string text);
int count_sentences(char input[255]);

int main(void)
{
    // string input = get_string("Input: ");
    char text[255];
    int res;
    printf("Text: ");
    gets(text);
    res = cl_index_calc(text);
    if (res < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (res > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", res);
    }
    return 0;
}

int cl_index_calc(char input[255])
{
    // get count
    int num_l = count_letters(input);
    int num_w = count_words(input);
    int num_s = count_sentences(input);
    printf("Letters: %d\tWords: %d\tSentences: %d\n", num_l, num_w, num_s);

    // calculate average
    // remember to convert the type so the result will not be integer
    float avrg_l = (float)num_l / (float)num_w * 100.0;
    float avrg_s = (float)num_s / (float)num_w * 100.0;
    // calculate index
    float index;
    index = 0.0588 * avrg_l - 0.296 * avrg_s - 15.8;
    return (int)round(index);
}

int count_letters(char input[255])
{
    int count = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]) != 0)
        {
            count++;
        }
    }
    return count;
}

int count_words(char input[255])
{
    int count = 0;
    // flag = 1 when it's alpha, 0 when it's a sign
    for (int i = 0, n = strlen(input) , flag = 0; i < n; i++)
    {
        if (isalpha(input[i]) == 0)
        {
            // avoiding signs ' and -
            if (input[i] == '-' || input[i] == '\'')
            {
                continue;
            }
            // after a , or . or ! folows a space with flag judgement avoiding continuous increment.
            else if (flag == 1)
            {
                flag = 0;
                count++;
            }
        }
        else 
        {
            flag = 1;
        }
    }
    return count;
}

int count_sentences(char input[255])
{
    int count = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]) == 0)
        {
            if (input[i] == '.' || input[i] == '!' || input[i] == '?')
            {
                count++;
            }
        }
    }
    return count;
}