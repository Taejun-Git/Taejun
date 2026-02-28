#include <stdio.h>

void larger_of(double * a, double * b);

int main(void)
{
    double a, b;

    while (printf("두 수 입력(q 입력시 종료): "), scanf("%lf %lf", &a, &b) == 2)
        larger_of(&a, &b);

    printf("종료!\n");
}

void larger_of(double * a, double * b)
{
    if (*a >= *b)
        *b = *a;
    else 
        *a = *b;

    printf("%.1lf %.1lf\n", *a, *b);
}