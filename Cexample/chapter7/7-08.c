#include <stdio.h>

#define TAX_RATE1 0.15
#define TAX_RATE2 0.2
#define TAX_RATE3 0.25
#define TAX_UPPER1 300
#define TAX_UPPER2 450
#define BREAK1 TAX_RATE1 * TAX_UPPER1
#define BREAK2 BREAK1 + ((TAX_UPPER2 - TAX_UPPER1) * TAX_RATE2)
#define OVER_TIME 40

int main()
{
    int work_hour;
    int count;
    int num;
    double pay;
    double work_overtime;
    double taxes;
    double wage;
    
    while (1)
    {
        printf("*************************************************************************\n");
        printf("자신의 기본급에 해당하는 번호를 선택하시오(끝내려면 5번을 선택하시오):\n");
        printf("1)시간당 $8.75                  2) 시간당 $9.33\n");
        printf("3)시간당 $10.00                 4) 시간당 $11.20\n");
        printf("5) 종료\n");
        printf("*************************************************************************\n");
        
        if ((count = scanf("%d", &num)) == 1 && 1 <= num && num <= 5)
        {
            switch (num)
            {
                case 1 : wage = 8.75;
                         break;
                         
                case 2 : wage = 9.33;
                         break;
                         
                case 3 : wage = 10.00;
                         break;
                         
                case 4 : wage = 11.20;
                         break;
                         
                case 5 : goto end;
            }
            
            printf("주당 근무 시간을 입력하시오: ");
        
            if ((count = scanf("%d", &work_hour)) == 1 && work_hour >= 0)
            {
                if (work_hour <= OVER_TIME)
                    pay = work_hour * wage;
                else if (work_hour > OVER_TIME)
                    pay = wage * OVER_TIME + wage * 0.5 * (work_hour - OVER_TIME);
                
                if (pay <= TAX_UPPER1)
                    taxes = pay * 0.15;
                else if (pay <= TAX_UPPER2)
                    taxes = BREAK1 + ((pay - TAX_UPPER1) * TAX_RATE2);
                else
                    taxes = BREAK2 + ((pay - TAX_UPPER2) * TAX_RATE3);
            }
            
            printf("GROSS PAY: %.1f TAXES: %.1f NET PAY: %.1f\n", pay, taxes, pay - taxes);
            
        }
        else 
        {
            printf("다시 선택하시오\n");
            break;
        }
    }
    
    end : printf("종료!\n");
    
    return 0;
}