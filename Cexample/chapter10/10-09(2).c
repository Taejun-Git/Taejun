#include <stdio.h>

void vla(int m, int n, double arr[m][n], double copy_arr[m][n]);

int main(void)
{
    int i, j;
    int m = 3;
    int n = 5;

    double arr[m][n];
    double copy_arr[m][n];

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

    vla(m, n, arr, copy_arr);

    return 0;
}

void vla(int m, int n, double arr[m][n], double copy_arr[m][n])
{
    int i, j;

    for (i = 0; i < m; i++)
        ;//copy_arr[i] = arr[i];
}