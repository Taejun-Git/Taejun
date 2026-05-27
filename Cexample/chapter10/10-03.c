#include <stdio.h>

int biggest(int arr[], int n);

int main(void)
{
    int arr[9] = {6, 4, 3, 2, 7, 8, 5, 9, 1};

    printf("%d", biggest(arr, 9));

    return 0;
}

int biggest(int arr[], int n)
{
    int i = 0;
    int big = 0;

    while(i < n)
    {
        if (big < arr[i])
            big = arr[i];
        
        i++;
    }

    return big;
}