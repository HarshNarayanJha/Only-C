#include<stdio.h>
#include "num_utils.h"

int reverse_num(int num) {
    int num_digits = get_num_digits(num);

    int digits[num_digits];
    int num_rev = 0;

    for (int n = 0; n < num_digits; ++n) {
        if (n == 0) {
            digits[n] = num % 10;
        } else {
            int high = ipow(10, (n+1));
            int low = ipow(10, n);
            digits[n] = ((num % high) - (num % low)) / low;
        }
    }

    int i, k = 0;
    for (i = 0; i < num_digits; i++)
        k = 10 * k + digits[i];

    return k;
}

int main() {
    int num = 245;

    int reverse = reverse_num(num);

    printf("%d -> %d", num, reverse);
}