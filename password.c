// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int n = strlen(password);
    bool upper = false;
    bool lower = false;
    bool num = false;
    bool sym = false;

    for (int i = 0; i < n; i++)
    {
        char c = password[i];
        if (isupper(c))
            upper = true;
        else if (islower(c))
            lower = true;
        else if (isdigit(c))
            num = true;
        else if (ispunct(c))
            sym = true;
    }

    if (upper && lower && num && sym)
    {
        return true;
    }

    else
    {
        return false;
    }
}