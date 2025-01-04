#include <stdio.h>
#include <ctype.h>

#define D_F_BREAK1 5  //D_F -> delivery_fee
#define D_F_BREAK2 20
#define D_F_1 6.5 //D_F_BREAK1의 배달비
#define D_F_2 14.0
#define discount 0.95

double order_system(void);
int a_o(void);
double delivery_fee(double total_amount);
double pay(double ac_price, double be_price, double ca_price);
double artichokes_pay(double ac_total_amount);
double beets_pay(double be_total_amount);
double carrots_pay(double ca_total_amount);

int main(void)
{
    order_system();

    return 0;
}

double order_system(void)
{
    char ch;
    double total_pay;
    double ac_amount, be_amount, ca_amount;
    double total_amount;
    double ac_total_amount = 0;
    double be_total_amount = 0;
    double ca_total_amount = 0;

    while (1)
    {
        printf("\n=================================ORDER VAGETABLES=================================\n");
        printf("a) artichokes               b) beets               c) carrots              q) quit\n");
        printf("==================================================================================\n");

        while ((ch = getchar()) == '\n') 
            /* skip enter*/;

        ch = tolower(ch);

        printf("구입할 파운드 양 입력: ");
        
        if (ch == 'a')
            scanf("%lf", &ac_amount);
        else if (ch == 'b')
            scanf("%lf", &be_amount);
        else if (ch == 'c')
            scanf("%lf", &ca_amount);
        else
            ;

        if (ch != 'q')
        {
            switch (ch)
            {
                case 'a' : ac_total_amount += ac_amount;
                           artichokes_pay(ac_total_amount);
                           if(a_o() == 1)
                                continue;
                           else
                                goto end;
    
                           
                case 'b' : be_total_amount += be_amount; 
                           beets_pay(be_total_amount);
                           if(a_o() == 1)
                                continue;
                           else
                                goto end;

                case 'c' : ca_total_amount = ca_amount;
                           carrots_pay(ca_total_amount);
                           if(a_o() == 1)
                                continue;
                           else
                                goto end;

                default : goto gg;
            }
        }
        else
            break;
        // 1.어떤걸 주문 받을 지 선택 -> 2. 양을 입력 받기. -> 3. 추가주문 (Y -> 다시 양 입력 받기 -> 전부 다 받으면 출력) / (N -> 결과 출력)
        //양 입력 받고 추가주문?
    }
    
    end: ;

    total_amount = ac_total_amount + be_total_amount + ca_total_amount;
    total_pay = pay(artichokes_pay(ac_total_amount), beets_pay(be_total_amount), carrots_pay(ca_total_amount));


    printf("\n=======================================================================\n");
    printf("1) 각 야채별 파운드당 가격\n");
    printf("artichokes: $2.05   beets: $1.15    carrots: $1.09\n");
    printf("2) 주문양\n");
    printf("artichokes: %.1f found   beets: %.1f found    carrots: %.1f found\n", ac_total_amount, be_total_amount, ca_total_amount);
    printf("3) 각 야채당 주문 비용\n");
    printf("artichokes: $%.1f   beets: $%.1f   carrots: $%.1f\n", artichokes_pay(ac_total_amount), beets_pay(be_total_amount), carrots_pay(ca_total_amount));
    printf("4) 총 구매 합산\n");
    printf("$%.1f\n", pay(artichokes_pay(ac_total_amount), beets_pay(be_total_amount), carrots_pay(ca_total_amount)));
    if (total_pay < 100)
    {
        printf("5) 배달비\n");
        printf("$%.1f\n", delivery_fee(total_amount));
        printf("6) 총 청구금액\n");
        printf("$%.1f\n", (pay(artichokes_pay(ac_total_amount), beets_pay(be_total_amount), carrots_pay(ca_total_amount)) - delivery_fee(total_amount)));
        printf("=======================================================================\n");
    }
    else
    {
        printf("5) 할인가격\n");
        printf("%.1f\n", pay(artichokes_pay(ac_total_amount), beets_pay(be_total_amount), carrots_pay(ca_total_amount)) * discount);
        printf("6) 배달비\n");
        printf("$%.1f\n", delivery_fee(total_amount));
        printf("7) 총 청구금액\n");
        printf("$%.1f\n", (pay(artichokes_pay(ac_total_amount), beets_pay(be_total_amount), carrots_pay(ca_total_amount)) * discount) - delivery_fee(total_amount));
        printf("=======================================================================\n");
    }

    gg: printf("END!\n");
}

int a_o(void)
{
    char additional_order = 'A';
    int check;

    printf("추가주문? Y/N:");
    
    while ((additional_order = getchar()) == '\n')  // a / enter는 남아있으니까 enter를 빼야됨
        /* skip enter */ ;

    //additional_order = getchar(); //-> 첫 번쨰 입력떄 남은 엔터가 대입 됨.
    additional_order = toupper(additional_order);

    if(additional_order == 'Y' || additional_order == 'N')
    {
        if (additional_order == 'Y')
            check = 1;
        else 
            check = 0;
    }
    
    return check;
}

double delivery_fee(double total_amount)
{
    double d_f;

    if (total_amount <= D_F_BREAK1)
        d_f = D_F_1;
    else if (total_amount <= D_F_BREAK2)
        d_f = D_F_2;
    else
        d_f = D_F_2 + ((total_amount - D_F_BREAK2) * 0.5);

    return d_f;
}

double pay(double ac_price, double be_price, double ca_price)
{
    double total_price;
    total_price = ac_price + be_price + ca_price;
    
    return total_price;
}

double artichokes_pay(double ac_total_amount)
{
    return ac_total_amount * 2.05;
}

double beets_pay(double be_total_amount)
{
    return be_total_amount * 1.15;
}

double carrots_pay(double ca_total_amount)
{
    return ca_total_amount * 1.09;
}