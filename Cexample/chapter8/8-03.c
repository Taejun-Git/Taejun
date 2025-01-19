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

        if (islower(ch)) // islower(ch) 만 해도 되네 -> 참이면 lower오를꺼고 거짓이면 안오르는 건 마찬가지니까((islower(ch) != 0) == islower(ch)))
            ++lower;
        else if (isupper(ch))
            ++upper;
        else
            continue;
    }

    printf("\n 소문자 수: %d 대문자 수: %d\n", lower, upper);

    return 0;
}