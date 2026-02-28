#include <stdio.h>

double big(double arr[], int n);
double small(double arr[], int n);

int main(void)
{
    double arr[9] = {9, 2, 3, 1, 7, 6, 8, 5, 4};

    printf("%.1f", big(arr, 9) - small(arr, 9));

    return 0;
}

double big(double arr[], int n)
{
    int i = 0;
    double big = 0;

    while(i < n)
    {
        if (big < arr[i])
            big = arr[i];
        
        i++;
    }

    return big;
}

double small(double arr[], int n)
{
    int i = 0;
    double small = big(arr, 9);

    while(i < n)
    {
        if (small > arr[i])
            small = arr[i];
        
        i++;
    }

    return small;
}

//최고와 최저 구하는 함수 만들어서 둘을 빼면 되고
    //한 함수에서 최고 최저 둘다 구할 수 있나?