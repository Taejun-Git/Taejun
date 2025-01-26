#include <stdio.h>

int to_base_n(void);
void to_binary(int n, int integer);

int main(void)
{
    int integer;

    while (printf("10진수 정수를 입력하시오.\n"), (scanf("%d", &integer) != 1)) 
    {
        while (getchar() != '\n')
            continue;

        continue;
    }
    to_binary(to_base_n(), integer);

    return 0;
}

int to_base_n(void)
{
    int n;
    int a;

    while (printf("2에서 10사이의 정수를 입력하시오.\n"), scanf("%d", &n) != 1 || (n < 2 || n > 10))
    {
        while (getchar() != '\n')
            continue;
        
        continue;
    }

    return n;
}

void to_binary(int n, int integer)
{
    int a;

    a = integer % n;

    if (integer >= n)
        to_binary(n, integer / n); // integer = integer / n 
    else 
        a = integer;
    
    printf("%d", a);
}

/*void to_binary(int n, int integer)
{
    int a;

    while (integer >= n)
    {
        a = integer % n;

        printf("%d", a);

        integer = integer / n;
    }

    a = integer;

    printf("%d", a);
} 거꾸로 출력돠게 하려면 어떻게 해야하지?*/ 
