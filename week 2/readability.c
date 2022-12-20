#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //prompt user for text
    string text = get_string("Text: ");

// int define letters words sentences
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        else if (text[i] == ' ')
        {
            words++;
        }

        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
//before grade 1 (negatives)
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
//after grade 16
    if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
//everything else print
    else
    {
        printf("Grade %i\n", index);
    }
}