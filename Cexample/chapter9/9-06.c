#include <stdio.h>

double compare(double * a, double * b, double * c);

int main(void)
{
    double a, b,c ;

    while (printf("세개의 수 입력(q 입력시 종료): "), scanf("%lf %lf %lf", &a, &b, &c) == 3)
        compare(&a, &b, &c);

    printf("종료!\n");
}

double compare(double * a, double * b, double * c)
{
    double temp;
    double max, mid, min;

    if (*a >= *b && *a >= *c)
    {
        max = *a;

        if(*b >= *c)
            mid = *b, min = *c; 
        else
            mid = *c, min = *b; 

    }
    else if (*b >= *a && *b >= *c)
    {
        max = *b;

        if(*a >= *c)
            mid = *a, min = *c; 
        else
            mid = *c, min = *a; 
    }
    else
    {
        max = *c;

        if(*a >= *b)
            mid = *a, min = *b; 
        else
            mid = *b, min = *a; 
    }

    printf("max = %.2f mid = %.2f min = %.2f\n", max, mid, min);
}