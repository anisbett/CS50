#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i;
    int height;
    do
    {
         height = get_int("Height: ");
    }

    while (height < 1 || height > 8);

     for ( i = 1; i <= height; i++)
    {
        int column;
        for (int space = 0; space < height - i; space++) {
            printf(" ");
        }

        for (column = 0; column < i; column++)
        {

            printf("#");
        }
        printf("\n");
    }

}