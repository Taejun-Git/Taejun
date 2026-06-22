#include <stdio.h>
#include <ctype.h>

void ch_(char ch, int i, int j);

int main(void)
{
    char ch;
    int i, j;
    
    while (printf("문자 입력(# 입력시 종료): "), (ch = getchar()) != '#')
    {
        if (isspace(ch) == 1 || (ch < 1 || ch > 128))
        {
            printf("한글 입력 X\n");

            while (getchar() != '\n')
                continue;

            continue;
        }

        while (getchar() != '\n')
                continue;

        printf("출력할 행과 열 입력: ");

        while (scanf("%d %d", &i, &j) != 2)
            printf("범위 다시 입력(숫자만 작성): ");

        ch_(ch, i, j);
        
        while (getchar() != '\n')
                continue;
                
    }
    
    return 0;
}

void ch_(char ch, int i, int j)
{
    for (int a = 0; a < i; a++)
    {
        for(int b = 0; b < j; b++)
            putchar(ch);
        
        putchar('\n');
    }  //중첩 루프 안쓰는 법 있나?
}
