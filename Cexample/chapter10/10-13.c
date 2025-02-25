#include <stdio.h>

void input(double arr[][5], int n);
double row_average(double arr[], int n);
double average(double arr[][5], int n);
double max(double arr[][5], int n);

int main(void)
{
    int i = 0;
    double arr[3][5];

    input(arr, 3);
    while (i < 3)
    {
        printf("%d행 평균값: %.1f\n", i + 1, row_average(arr[i], 5));
        i++;
    }
    printf("전체 값들의 평균값: %.1f\n", average(arr, 3));
    printf("15개의 값 중 최대값: %.1f", max(arr, 3));

    return 0;
}

void input(double arr[][5], int n)
{
    int i, j;
    double a;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%lf", &a); //scanf("%lf ", &a); <- 띄어쓰기 넣으면 안됨
            arr[i][j] = a;
        }
    }
    
   /* for (i = 0; i < n; i++)
        scanf("%lf %lf %lf %lf %lf", arr[i], arr[i] + 1, arr[i] + 2, arr[i] + 3, arr[i] + 4);*/
        
}

double row_average(double arr[], int n)
{
    int i;
    double row_total;

    for(i = 0, row_total = 0; i < n; i++)
        row_total += arr[i];

    return row_total / n;
}
double average(double arr[][5], int n)
{
    int i, j;
    double total;

    for (i = 0, total = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++)
            total += arr[i][j]; 
    }

    return total / 15;
}

double max(double arr[][5], int n)
{
    int i, j;
    double max = arr[0][0];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (max < arr[i][j])
                max = arr[i][j];
        }
    }

    return max;       
}