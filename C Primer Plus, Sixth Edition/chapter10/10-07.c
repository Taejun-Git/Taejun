#include <stdio.h>

void copy_arr(int m, int n, double arr[m][n], double c_arr[m][n]);

int main(void)
{
    int i, j;
    int m = 5;
    int n = 5;

    double arr[m][n];
    double c_arr[m][n];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = i + j;
            printf("%.1f ", arr[i][j]);
        }

        putchar('\n');
    }

    putchar('\n');
    
    copy_arr(m, n, arr, c_arr);

    return 0;
}

void copy_arr(int m, int n, double arr[m][n], double c_arr[m][n])
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c_arr[i][j] = arr[i][j];
            printf("%.1f ",c_arr[i][j]);
        }

        putchar('\n');
    }
}