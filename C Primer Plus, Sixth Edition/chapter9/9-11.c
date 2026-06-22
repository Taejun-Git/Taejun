#include <stdio.h>

int fibonacci(int a);

int main(void)
{
    int a;

    while (printf("숫자를 입력하시오.\n"), (scanf("%d", &a) != 1)) 
    {
        while (getchar() != '\n')
            continue;

        continue;
    }

    printf("%d\n", fibonacci(a));
}

int fibonacci(int a)
{   
    int m = 1, n = 1;
    int i;
    
    if (a <= 2)
        return 1;
    else
    {
        for (i = 3; i <= a; i = i + 2) 
        {
            m = m + n;
            n = m + n;
        }
    }

    if (a % 2 == 0)
        return n;
    else 
        return m;
}

/*

  m  n   m  n                                 -> m은 홀수 n은 짝수
a 1  2 | 3  4 | 5  6 | 7   8  | 9   10
  1  1 | 2  3 | 5  8 | 13  21 | 34  55        -> m값과 n값이 i가 2씩 증가 할 때 마다 계산하려고 함. -> a가 짝수 단위에서 한번씩 m과 n이 갱신되도록 a = 4 m과 n 한번 갱신 a = 6 두 번 갱신

*/
/*
int fibonacci(int a)
{
    if (a <= 2) 
        return 1;

    int m = 1, n = 1;
    // m은 (n-1)번째 값, n은 (n)번째 값
    for (int i = 3; i <= a; i++) {
        int temp = m + n;
        m = n;
        n = temp;
    }

    return n; // a가 홀수든 짝수든 마지막 n이 원하는 값
}
*/