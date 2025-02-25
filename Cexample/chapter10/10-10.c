#include <stdio.h>

void plus(int * arr_1, int * arr_2, int * arr_3, int n);

int main(void)
{
    int arr_1[4] = {2, 4, 5, 8};
    int arr_2[4] = {1, 0, 4, 6};
    int arr_3[4];

    plus(arr_1, arr_2, arr_3, 4);

    return 0;
}

void plus(int * arr_1, int * arr_2, int * arr_3, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        arr_3[i] = arr_1[i] + arr_2[i];
        printf("%d ", arr_3[i]);
    }
}