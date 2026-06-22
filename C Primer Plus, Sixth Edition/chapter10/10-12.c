#include <stdio.h>

#define YEARS 5
#define MONTHS 12
//해당 년도 평균 강우량, 5년 동안 연 평균 강수량, 월 평균 강수량 

void a(const float rain[][MONTHS]); 
void b(const float rain[][MONTHS]);

int main(void)
{
    const float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };

    a(rain);
    b(rain);

    return 0;
}

void a(const float rain[][MONTHS])
{
    int i, j;
    float total;
    float subtot;

    printf("년도      강수량\n");

    for (i = 0, total = 0; i < YEARS; i++)
    {
        for (j = 0, subtot = 0; j < MONTHS; j++)
            subtot += rain[i][j];

        printf("%d      %.1f\n", i + 2010, subtot);

        total += subtot; 
    }

    printf("\n연 평균 강수량: %.1f\n", total / YEARS);
}

void b(const float rain[][MONTHS])
{
    int i, j;
    float subtot;
    printf("\n월 평균 강우량은 다음과 같습니다.\n\n");

    for (i = 0; i < MONTHS; i++)
        printf("%d월 ", i + 1);
    
    putchar('\n');

    for (j = 0; j < MONTHS; j++)
    {
        for (i = 0, subtot = 0; i < YEARS; i++)
            subtot += rain[i][j];

        printf("%.1f ", subtot / YEARS);
    }

    putchar('\n');
}