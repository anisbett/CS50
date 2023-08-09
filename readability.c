#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int compute_index(int letters, int words, int sentences);

int main(void)
{
    string passage = get_string("Text: ");

    int letters = count_letters(passage);

    int words = count_words(passage);

    int sentences = count_sentences(passage);

    int index = compute_index(letters, words, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
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
    int ltrs = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            ltrs++;
        }
    }

    return ltrs;
}

int count_words(string text)
{
    int wrds = 0;
    int n = strlen(text);
    bool inside_word = false; // Flag to track if currently inside a word

    for (int i = 0; i < n; i++)
    {
        char c = text[i];

        if (isalpha(c) || c == '\'')
        {
            if (!inside_word) // Transition from non-word to word
            {
                inside_word = true;
                wrds++;
            }
        }
        else
        {
            inside_word = false; // Transition from word to non-word
        }
    }

    return wrds;
}

int count_sentences(string text)
{
    int sen = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        char c = text[i];

        // Check for end-of-sentence punctuation
        if (c == '.' || c == '!' || c == '?')
        {
            sen++;
        }
    }

    return sen;
}

int compute_index(int letters, int words, int sentences)
{
    int index = round(0.0588 * ((float)letters / words * 100.0) - 0.296 * ((float)sentences / words * 100) - 15.8);
    return index;
}