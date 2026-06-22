#include <stdio.h>

void copy_arr(double * target1, double * source, int n);

int main(void)
{
    double arr[7] = {1, 2, 3, 4, 5, 6, 7};
    double source[3];

    copy_arr(arr + 2, source, 3);
}

void copy_arr(double * target1, double * source, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        source[i + 2] = target1[i + 2];
        printf("%.1f ", source[i + 2]);
    }

    putchar('\n');
}// 전달인자를 copy_arr(arr, source, 3) -> copy_arr(arr + 2, source, 3)하는게 더 깔끔함