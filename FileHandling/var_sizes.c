/*
 Write a C program to find the median element in an array.
Median: takes an int array and the array's size as arguments. It should return
the median value of the array elements, as a double. If the values are sorted,
the median is the middle value. If the set contains an even number of values,
the median is the average of the two middle values. Assume the values in the
array is already sorted. Do not use square brackets anywhere in the function,
not even the parameter list (use pointers instead).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double median(int *, int);

    int *arr;
    int N = 4;
    arr = (int *)malloc(sizeof(int) * N);
    *(arr + 0) = 4;
    *(arr + 1) = 5;
    *(arr + 2) = 8;
    *(arr + 3) = 9;

    for (int i = 0; i < N; ++i)
    {
        // printf("%d", *(arr+i));
    }

    double m = median(arr, N);
    printf("%lf", m);

    free(arr);
}

double median(int *arr, int n)
{
    int r = n - 1;
    int m = r / 2;
    if (n % 2 == 0)
    {
        int s = *(arr + m) + *(arr + m + 1);
        // printf("%ld", s);
        return s / 2.0;
    }
    else
    {
        return *(arr + m);
    }
}