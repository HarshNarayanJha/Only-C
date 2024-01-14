// S = x/1! - x**3 / 3! + x**5 / 5! - x**7 / 7! + x**9 / 9! ... x**n / n!

#include <stdio.h>

int main() {
    int x = 2;
    int n = 3;
    double S = 0.0;

    int prev_fact = 1;

    int term = x;
    
    for (int i = 1; i < n + 1; i++) {
        S += term / (double) (prev_fact);
        printf("%d\n", prev_fact);
        term *= -x*x;
        prev_fact *= (prev_fact+1)*(prev_fact+2);
    }

    printf("%.3f", S);
}