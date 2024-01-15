#include "num_utils.h"

int ipow(int a, int n) {
    int res = 1;
    for (int i = 0; i < n; ++i) {
        res *= a;
    }

    return res;
}

int get_num_digits(int num) {
    int val = 0;
    int d = 0;
    while (val != num) {
        val = num % ipow(10, d);
        d++;
    }

    return --d;
}