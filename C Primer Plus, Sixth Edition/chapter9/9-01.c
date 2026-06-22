#include <stdio.h>

double min(double x, double y);

int main(void)
{
    double x = 1.3;
    double y = 1.3;

    printf("%.1f와 %.1f 중 작은 값은 %.1f\n", x, y, min(x, y));

    return 0;
}

double min(double x, double y)
{
    if (x <= y)
        return x;
    else
        return y;
    //삼항 연산자 쓰는 것도 있음 return a > b ? a : b;
}