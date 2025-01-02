#include <stdio.h>

#define SINGLE_TAX_LIMIT 17850
#define BREADWINNER_TAX_LIMIT 23900
#define DUAL_INCOME_ADD_TAX_LIMIT 29750
#define DUAL_INCOME_DIV_TAX_LIMIT 14875
#define DEFAULT_TAX 0.15
#define EXCESS_TAX 0.28
#define SG_TAX_LIMIT SINGLE_TAX_LIMIT * DEFAULT_TAX
#define BD_TAX_LIMIT BREADWINNER_TAX_LIMIT * DEFAULT_TAX
#define DIA_TAX_LIMIT DUAL_INCOME_ADD_TAX_LIMIT * DEFAULT_TAX
#define DID_TAX_LIMIT DUAL_INCOME_DIV_TAX_LIMIT * DEFAULT_TAX

double single(double income);
double breadwinner(double income);
double dual_income_add(double income);
double dual_income_div(double income);


int main(void)
{
    double income;
    int type;
    int check;

    while (1)
    {
        printf("**************************************************************************\n");
        printf("해당하는 과세 구분의 번호를 입력하시오.\n");
        printf("1) 독신     2) 가장     3)맞벌이, 합산     4)맞벌이, 별산       5) 종료\n");
        printf("**************************************************************************\n");

        if ((check = scanf("%d", &type)) == 1 &&  1 <= type && type <= 4)
            ;
        else if (type == 5)
            break;
        
        printf("\n과세 대상 소득을 입력하시오: ");

        scanf("%lf", &income);

        switch (type)
        {
            case 1 : printf("\n과세구분: 싱글, 과세 대상 소득: %.1f, 소득세: %.1f\n\n", income, single(income));
                     break;

            case 2 : printf("\n과세구분: 가장, 과세 대상 소득: %.1f, 소득세: %.1f\n\n", income, breadwinner(income));
                     break;

            case 3 : printf("\n과세구분: 맞벌이 / 합산, 과세 대상 소득: %.1f, 소득세: %.1f\n\n", income, dual_income_add(income));
                     break;

            case 4 : printf("\n과세구분: 맞벌이 / 별산, 과세 대상 소득: %.1f, 소득세: %.1f\n\n", income, dual_income_div(income));
                     break;
        }
    }

    printf("종료!\n");

    return 0;
}

double single(double income)
{
    double tax;

    if (income <= SINGLE_TAX_LIMIT)
        tax = income * DEFAULT_TAX;
    else
        tax = SG_TAX_LIMIT + ((income - SINGLE_TAX_LIMIT) * EXCESS_TAX);
        
    return tax;
}

double breadwinner(double income)
{
    double tax;

    if (income <= BREADWINNER_TAX_LIMIT)
        tax = income * DEFAULT_TAX;
    else
        tax = BD_TAX_LIMIT + ((income - BREADWINNER_TAX_LIMIT) * EXCESS_TAX);
        
    return tax;
}

double dual_income_add(double income)
{
    double tax;

    if (income <= DUAL_INCOME_ADD_TAX_LIMIT)
        tax = income * DEFAULT_TAX;
    else
        tax = DIA_TAX_LIMIT + ((income - DUAL_INCOME_ADD_TAX_LIMIT) * EXCESS_TAX);
        
    return tax;
}

double dual_income_div(double income)
{
    double tax;

    if (income <= DUAL_INCOME_DIV_TAX_LIMIT)
        tax = income * DEFAULT_TAX;
    else
        tax = DIA_TAX_LIMIT + ((income - DUAL_INCOME_DIV_TAX_LIMIT) * EXCESS_TAX);
        
    return tax;
}
