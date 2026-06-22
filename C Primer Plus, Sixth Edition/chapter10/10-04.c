#include <stdio.h>

int biggest(double arr[], int n);

int main(void)
{
    double arr[9] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9};

    printf("%d", biggest(arr, 9));

    return 0;
}

int biggest(double arr[], int n)
{
    int check;
    int i = 0;
    double big = 0;

    while(i < n)
    {
        if (big < arr[i])
        {
            big = arr[i];
            check = i;
        }
        
        i++;
    }

    return check;
}