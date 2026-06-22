#include <stdio.h>

double harmonic_mean(double a, double b);

int main(void)
{
    double a, b;

    while (printf("두 수 입력(q 입력시 종료): "), scanf("%lf %lf", &a, &b) == 2)
        printf("조화 평균: %.1lf\n", harmonic_mean(a, b));

    printf("종료!\n");
    
    return 0;
}

double harmonic_mean(double a, double b)
{
    double c, d;

    c = 1/a;
    d = 1/b;

    return 1 / ((c + d) / 2);
}