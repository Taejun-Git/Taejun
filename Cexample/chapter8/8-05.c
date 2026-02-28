#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char get_first(void);

int main(void)
{
    char ch = 0;
    int guess = 50;
    int up_guess = 100;
    int down_guess = 0;
    bool answer = false;

    printf("1에서 100까지 범위에 있는 한 정수를 생각하시오.\n");
    printf("내가 추측하지요. 내 추측이 맞다면 y로 응답하고, 추측보다 높으면 u, 낮으면 d를 입력하시오.\n");
    printf("당신이 생각하는 수가 %d입니까?\n", guess);

    while (answer != true)
    {
        ch = get_first(); //up면 up 고정 down면 down값 고정

        switch (ch)
        {
            case 'y' : printf("정답입니다!\n");
                       answer = true;
                       break;


            case 'u' : down_guess = guess;
                       guess = (up_guess + guess) / 2;
                       break;


            case 'd' : up_guess = guess;
                       guess = (down_guess + guess) / 2;
                       break;
            
            default : printf(" y, u ,d중에서만 입력하시오\n");
                      break;
        }

        printf("그러면 %d입니까?\n", guess);
    }

    printf("종료!\n");

    return 0;
}

char get_first(void)
{
    char ch;

    ch = getchar();

    while (getchar() != '\n')
        continue;

    return ch;
}