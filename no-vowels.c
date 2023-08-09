// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
   string newWord = replace(argv[1]);
    printf("%s\n", newWord);
}

string replace(string word)
{
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        switch(word[i])
    {
        case 'a':
        word[i] = '6';
        break;
        case 'e':
        word[i] = '3';
        break;
        case 'i':
        word[i] = '1';
        break;
        case 'o':
        word[i] = '0';
        break;
    }
    }
    return word;
}