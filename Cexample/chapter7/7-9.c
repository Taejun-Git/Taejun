#include <stdio.h>

int main()
{
    int num;
    int check;

    printf("2이상의 정수를 입력하시오:");
    
    while ((check = scanf("%d", &num)) == 1 && num > 0)
    {
        int i, j;
        for (i = 2; i <= num; i++)
        {
            int count = 0;
            for (j = 1; j <= i; j++)
            {
                if (i % j == 0)
                    ++count;
            }
            
            if (count == 2)
                printf("%d ", i);
        }
        printf("\n2이상의 정수를 입력하시오.");
    }
    return 0;
}