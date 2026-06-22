#include <stdio.h>

double power(double a, int b);

int main(void)
{
    double x, xpow;
    int exp;

    printf("어떤 수와 원하는 정수 거듭제곱수를");
    printf("입력하시오.\n끝내려면 q를"" 입력하시오.\n");

    while(scanf("%lf %d", &x, &exp) == 2)
    {
        xpow = power(x, exp);
        printf("%.3g의 %d승은 %.5g입니다.\n", x, exp, xpow);
        printf("두 수를 입력하시오 끝내려면 q를 입력하시오.\n");
    }

    printf("종료!\n");

    return 0;
}

double power(double a, int b)
{
    double pow = 1;
    int i;
    if (a != 0)
    {
        if (b > 0)
            for (i = 0; i < b; i++)
                pow *= power(a, b);
        else if (b == 0)
            /*a의 0승은 1*/;
        else 
            for (i = 0; i > b; i--)
                pow *= 1 / power(a, b);
    }
    else
        if (b != 0)
            pow = 0.0;
        else
        {
            printf("0의 0승은 정의 되지 않습니다.\n다시 입력하시오.");
            pow = 1;
        }
    
    return pow;
}