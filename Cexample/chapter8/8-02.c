#include <stdio.h>

int main(void)
{
    int ch;
    int count = 0;

    while ((ch = getchar()) != EOF)
    {
        count++;

        if (ch == '\n')
        {
            printf("\\n %d \n", ch);
            count = 0;
        }
        else if (ch == '\t')
            printf("\\t %d ", ch);
        else if (ch <= ' ')
            printf("^%c %d ", ch + 65, ch);
        else
            printf("%c %d ", ch, ch);


        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }

    putchar('\n');
    
    return 0;
}