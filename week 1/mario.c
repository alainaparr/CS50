#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, row, column, space;
// prompt user for height
    do
    {
        n = get_int("Height: ");
    }
//height defined
    while (n < 1 || n > 8);
//row
    for (row = 0; row < n; row++)
    {
//space
        for (space = 0; space < n - row - 1; space++)
        {
            printf(" ");
        }
//column
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
// move to next column
        printf("\n");
    }

}
