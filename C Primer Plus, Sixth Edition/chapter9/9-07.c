#include <stdio.h>
#include <ctype.h>

int func(char ch);

int main(void)
{
    char ch;
    int a, b, c;

    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            ch = tolower(ch);
            
            if (ch >= 'a' && ch <= 'z')
            {
                for(a = 0, b = 'a'; b <= ch; a++, b++)
                    continue;

                c = a;
            }
        }
        else
            c = -1;
        
        printf("%c %d\n", ch, c);
    }

    printf("%c %d\n", ch, c);
}
