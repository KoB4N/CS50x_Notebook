#include "cs50.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    int index = round(0.0588 * ((float) letters / words * 100) - 0.296 * ((float) sentences / words * 100) - 15.8); 
    
    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    } 
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    } 
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int letter_cnt = 0; 
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letter_cnt += 1;
        }
    }
    return letter_cnt;
}

int count_words(string text)
{
    // Return the number of words in text
    int word_cnt = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            word_cnt += 1;
        }
    }
    return word_cnt;
}

int count_sentences(string text)
{
    // Return the number of senteces in text
    int sentence_cnt = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_cnt += 1;
        }
    }
    return sentence_cnt; 
}