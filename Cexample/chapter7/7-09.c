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
            for (j = 1; j <= i; j++)  // for (int div = 2, numIsPrime = true; (div * div) <= num; div++
            {
                if (i % j == 0)       // if (num % div == 0)
                    ++count;          // numIsPrime = false;
            }                         // if (numIsPrime)
                                      // printf("%d is prime\n", num);
            if (count == 2)
                printf("%d ", i);
        }
        printf("\n2이상의 정수를 입력하시오.(q 입력시 종료): ");
    }
    return 0;
}