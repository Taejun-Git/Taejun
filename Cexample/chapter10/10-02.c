#include <stdio.h>

void copy_arr(double * target1, double * source, int n);
void copy_ptr(double * target2, double * source, int n);
void copy_ptr1(double * target3, double * source, double * l_source);
int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptr1(target3, source, source + 5);
    return 0;
}

void copy_arr(double * target1, double * source, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        target1[i] = source[i];
        printf("%.1f ", target1[i]);
    }

    putchar('\n');
}

void copy_ptr(double * target2, double * source, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        *(target2 + i) = *(source + i);
        printf("%.1f ", *(target2 + i));
    }

    putchar('\n');
}

void copy_ptr1(double * target3, double * source, double * l_source)
{
    while (source < l_source)
        printf("%.1f ", *(target3++) = *(source++));

    putchar('\n');
}