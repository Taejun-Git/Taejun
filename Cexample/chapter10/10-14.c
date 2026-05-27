#include <stdio.h>

void input(int m, int n, double arr[m][n]);
double row_average(int m, int n, double arr[m]);
double average(int m, int n, double arr[m][n]);
double max(int m, int n, double arr[m][n]);

int main(void)
{
    int m = 3;
    int n = 5;
    int i = 0;
    double arr[m][n];

    input(3, 5, arr);
    while (i < m)
    {
        printf("%d행 평균값: %.1f\n", i + 1, row_average(i, 5, arr[i]));
        i++;
    }
    printf("전체 값들의 평균값: %.1f\n", average(3, 5, arr));
    printf("15개의 값 중 최대값: %.1f", max(3, 5, arr));

    return 0;
}

void input(int m, int n, double arr[m][n])
{
    int i, j;
    double a;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &a); //scanf("%lf ", &a); <- 띄어쓰기 넣으면 안됨
            arr[i][j] = a;
        }
    }
    
   /* for (i = 0; i < n; i++)
        scanf("%lf %lf %lf %lf %lf", arr[i], arr[i] + 1, arr[i] + 2, arr[i] + 3, arr[i] + 4);*/
        
}

double row_average(int m, int n, double arr[m])
{
    int i;
    double row_total;

    for(i = 0, row_total = 0; i < n; i++)
        row_total += arr[i];

    return row_total / n;
}
double average(int m, int n, double arr[m][n])
{
    int i, j;
    double total;

    for (i = 0, total = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            total += arr[i][j]; 
    }

    return total / m * n;
}

double max(int m, int n, double arr[m][n])
{
    int i, j;
    double max = arr[0][0];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (max < arr[i][j])
                max = arr[i][j];
        }
    }

    return max;       
}