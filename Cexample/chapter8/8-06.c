#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void)
{
    printf("문장 입력: ");
    putchar(get_first());

    return 0;
}

char get_first(void)
{
    char ch;
    ch = getchar();

    while (isspace(ch))
        ch = getchar();

    return ch;
}