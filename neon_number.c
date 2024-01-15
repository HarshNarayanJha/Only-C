#include<stdio.h>
#include "num_utils.h"

bool check_neon(int num) {
    int num_sq = num*num;
    int num_digits = get_num_digits(num_sq);
    int digits[num_digits];

    for (int n = 0; n < num_digits; ++n) {
        if (n == 0) {
            digits[n] = num_sq % 10;
        } else {
            int high = ipow(10, (n+1));
            int low = ipow(10, n);
            digits[n] = ((num_sq % high) - (num_sq % low)) / low;
        }
    }

    int s = 0;
    for (int i = 0; i < num_digits; ++i) {
        s += digits[i];
    }

    // printf("%d", s);

    return s == num;
}

int main() {
    int num = 10;

    bool is_neon = check_neon(num);

    if (is_neon) {
        printf("%d is a neon number\n", num);
    } else {
        printf("%d is not a neon number\n", num);
    }
}