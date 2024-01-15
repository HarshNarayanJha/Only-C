#include <stdio.h>
#include "num_utils.h"

bool check_armstrong(int num) {
    // Somehow check number of digits
    int num_digits = get_num_digits(num);

    int digits[num_digits];

    for (int n = 0; n < num_digits; ++n) {
        if (n == 0) {
            digits[n] = num % 10;
        } else {
            int high = ipow(10, (n+1));
            int low = ipow(10, n);
            digits[n] = ((num % high) - (num % low)) / low;
        }
        // printf("%d ", digits[n]);
    }

    int s = 0;

    for (int i = 0; i < num_digits; ++i) {
        s += ipow(digits[i], num_digits);
    }

    if (s == num)
        return true;
    
    return false;
}

int main() {
    // Check Armstrong number

    int num = 54748;
    // int ones = num % 10;
    // int tens = ((num % 100) - (num % 10)) / 10;
    // int hundreds = (((num % 1000) - (num % 100))) / 100;

    bool is_armstrong = check_armstrong(num);

    // printf("%d", is_armstrong);

    if (is_armstrong) {
        printf("%d is an armstrong number!\n", num);
    } else {
        printf("%d is NOT an armstrong number!\n", num);
    }
}