#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    int lower = 0;
    int upper = 0;

    while ((ch = getchar()) != EOF)
    {
        putchar(ch);

        if (islower(ch) != 0)
            ++lower;
        else if (isupper(ch) != 0)
            ++upper;
        else
            continue;
    }

    printf("\n 소문자 수: %d 대문자 수: %d\n", lower, upper);

    return 0;
}