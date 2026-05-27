#include <stdio.h>

void reversal(double arr[], int n);

int main(void)
{
    int i;
    double arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    for (i = 0; i < 10; i++)
        printf("%.1f ", arr[i]);

    putchar('\n');

    reversal(arr, 10);

    return 0;
}

void reversal(double arr[], int n)
{
    int i;
    double temp;

    for (i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[(n - 1)- i];
        arr[(n - 1)- i] = temp;
    }

    i = 0;

    while (i < n)
    {
        printf("%.1f ", arr[i]);
        i++;
    }

    putchar('\n');
}
