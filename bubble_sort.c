#include<stdio.h>
#include "num_utils.h"

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int* bubble_sort(int* arr, int size) {
    bool swapped;
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (*(arr+j) > *(arr+j+1)) {
                swap(arr+j, arr+j+1);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
        
    }
    return arr;
}

int main() {
    const int NUM_ARRAY = 10;
    int nums[10] = {4, 6, 3, 7, 8, 10, 56, 2, -45, 100};
    bubble_sort(nums, NUM_ARRAY);

    for (int i = 0; i < NUM_ARRAY; ++i) {
        printf("%d, ", nums[i]);
    }

    printf("\n");
}