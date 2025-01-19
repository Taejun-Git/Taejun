#include <stdio.h>
#include <ctype.h>

void interface(void);
char get_first(void);
float get_float(void);
float add(void);
float subtract(void);
float multiply(void);
float divide(void);

int main(void)
{
    char ch;

    interface();

    while ((ch = get_first()) != 'q')
    {

        if (ch == '\n')
            continue;
        
        ch = tolower(ch);

        switch (ch)
        {
            case 'a' : add();
                       break;

            case 's' : subtract();
                       break;

            case 'm' : multiply();
                       break;

            case 'd' : divide();
                       break;

            case 'q' : goto end;

            default : printf("잘못된 입력입니다. 다시 입력하시오.\n");
                      break;
        }

        interface();
    }
    end : printf("종료!\n");

    return 0;
}

void interface(void)
{
    printf("원하는 연산에 해당하는 문자를 선택하시오.(끝내려면 q):\n");
    printf("a. add(덧셈)            s. subtract(뺼셈)\n");
    printf("m. multiply(곱셈)       d. divide(나눗셈)\n");
    printf("q. quit(종료)\n");
}

char get_first(void) //첫 문자 앞에 모든 공백을 받지 않기 위해 8-06 코드 이용
{
    char ch;

    ch = getchar();

    while (isspace(ch))
        ch = getchar();

    while (getchar() != '\n')
        continue;

    return ch;
}

float get_float(void)
{
    float a;

    while (scanf("%f", &a) != 1)
    {
        printf("수가 아닙니다.\n2.5 -/78E8, 3과 같은 수를 입력하시오: ");

        while (getchar() != '\n')
            continue;

        continue;
    }

    while (getchar() != '\n')
        continue;

    return a;
}

float add(void)
{
    float a, b;

    printf("첫 번째 수를 입력하시오: \n");
    a = get_float();

    printf("두 번째 수를 입력하시오: ");
    b = get_float();

    printf("\n%.1f + %.1f = %.1f\n", a, b, a + b);
}

float divide(void)
{
    float a, b;

    printf("첫 번째 수를 입력하시오: ");
    a = get_float();

    printf("두 번째 수를 입력하시오: ");
    b = get_float();

    printf("\n%.1f / %.1f = %.1f\n", a, b, a / b);
}

float subtract(void)
{
    float a, b;

    printf("첫 번째 수를 입력하시오: ");
    a = get_float();

    printf("두 번째 수를 입력하시오: ");
    b = get_float();

    printf("\n%.1f - %.1f = %.1f\n", a, b, a - b);
}

float multiply(void)
{
    float a, b;

    printf("첫 번째 수를 입력하시오: ");
    a = get_float();

    printf("두 번째 수를 입력하시오: ");
    b = get_float();

    printf("\n%.1f * %.1f = %.1f\n", a, b, a * b);
}
