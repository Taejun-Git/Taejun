#include <stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
    char ch;
    int i, j;
    printf("문자 입력: ");
    ch = getchar();

    printf("범위 입력:" );

    while (scanf("%d %d", &i, &j) != 2)
    {
        printf("범위 다시 입력(숫자만 작성): ");

        while (getchar() != '\n')
            continue;
    }

    chline(ch, i, j);

    return 0;    
}

void chline(char ch, int i, int j)
{
    int a = 1;
    while (a < i)
    {
        putchar(' ');
        a++;
    }

    while (i <= j)
    {
        putchar(ch);
        i++;
    }
}