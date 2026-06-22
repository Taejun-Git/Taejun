#include <stdio.h>

void array(double (* arr)[5], int n);
void two_times(double (* arr)[5], double (* arr_2)[5], int n);

int main(void)
{
    int i, j;
    double arr[3][5];
    double arr_2[3][5];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
            arr[i][j] = i + j;
    }

    array(arr, 3);
    two_times(arr, arr_2, 3);

    return 0;
}

void array(double (* arr)[5], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%.1f ", arr[i][j]);        

        putchar('\n');
    }

    putchar('\n');
}

void two_times(double (* arr)[5], double (* arr_2)[5], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++)
            arr_2[i][j] = 2 * arr[i][j];    
    }

    array(arr_2, 3);
}