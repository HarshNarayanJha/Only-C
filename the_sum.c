// S = x - x**3 + x**5 - x**7 + x**9 ... x**n

#include <stdio.h>

int main() {
    int x = 2;
    int n = 10;
    double S = 0.0;
    int coeff = 1;

    int term = x;

    for (int i = 1; i < n + 1; ++i) {
        S += coeff * term;
        term *= x*x;
        coeff *= -1;
    }

    printf("%.3f", S);
}