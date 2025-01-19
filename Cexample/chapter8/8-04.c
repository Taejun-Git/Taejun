#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int ch;
    float alphabet = 0;
    float word_count = 0;
    bool check = false;

    while ((ch = getchar()) != EOF)
    {
        if (isspace(ch) == 0)
        {
            check = true;
            ++alphabet;
        }

        if (check == true && isspace(ch) != 0)
        {
            check = false;
            word_count += 1;
        }
    }

    printf("단어 당 사용된 평균 글자 수: %.1f\n", alphabet / word_count);

    return 0;
}