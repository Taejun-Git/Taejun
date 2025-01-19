#include <stdio.h>
#include <ctype.h>

#define over_work_pay_rate 1.5
#define tax_1_rate 0.15
#define tax_2_rate 0.20
#define tax_other_rate 0.25
#define tax_1_section 300
#define tax_2_section 450
#define tax_1 tax_1_section * tax_1_rate
#define tax_2 tax_1 + ((tax_2_section - tax_1_section) * tax_2_rate)
#define over_40 40 

float net_pay(float pay, float work_hour);
float taxes(float net_pay);
char get_first(void);
void interface(void);

int main(void)
{
    int ch;
    float work_hour;
    float pay;

    interface();

    while ((ch = get_first()) != 'q') //처음에 ((ch = get_first()), ch != 'q') 라고 조건문 작성
    {
        if (ch == '\n')
            continue; //처음에 enter로 입력받으면 프로그램이 제대로 작동안함.

        ch = tolower(ch); //ch가 대문자로 입력받을 수 있기 때문에 사용자 배려차원 -> 답지 보고 작성

        switch (ch)
        {
            case 'a' : pay = 8.75;
                       break;

            case 'b' : pay = 9.33;
                       break;

            case 'c' : pay = 10.00;
                       break;

            case 'd' : pay = 11.25;
                       break;

            case 'q' : goto end;

            default : printf("a/b/c/d/q 중 하나를 입력하시오\n");
                      break;
        }

        printf("노동한 시간 입력: ");
        scanf("%f", &work_hour);

        float gross_pay = net_pay(pay ,work_hour) - taxes(net_pay(pay, work_hour));

        printf("\n총 소득: %.2f / 세금: %.2f / 순 소득: %.2f\n", gross_pay, taxes(net_pay(pay, work_hour)), net_pay(pay, work_hour));

        interface();
    }

    end : interface();

    return 0;
}

float net_pay(float pay, float work_hour)
{
    float work_pay;

    if (work_hour <= over_40)
        work_pay = pay * work_hour;
    else
        work_pay = (over_40 * pay) + ((pay * over_work_pay_rate) * (work_hour - over_40));

    return work_pay;
}

float taxes(float net_pay)
{
    float tax;

    if (net_pay <= tax_1_section)
        tax = net_pay * tax_1_rate;
    else if (net_pay <= tax_2_section)
        tax = tax_1 + ((net_pay - tax_1_section) * tax_2_rate);
    else 
        tax = tax_2 + ((net_pay - tax_2_section) * tax_other_rate);

    return tax;
}

char get_first(void) //첫 문자 앞에 모든 공백을 받지 않기 위해 8-06 코드 이용
{
    char ch;
    ch = getchar();

    while (isspace(ch))
        ch = getchar();

    return ch;
}

void interface(void)
{
    printf("***************************************************************\n");
    printf("자신의 기본급에 해당하는 문자를 선택하시오(끝내려면 q):\n");
    printf("a) 시간당 $8.75             b) 시간당 $9.33\n");
    printf("c) 시간당 $10.00             d) 시간당 $11.20\n");
    printf("q) 종료!\n");
    printf("***************************************************************\n");
}