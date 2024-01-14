#include <stdio.h>

int main() {
    int current = 1;
    int last = 1;
    int last2 = 0;
    int n = 25;

    for (int i = 0; i < n; ++i) {
        printf("%d ", current);
        current = last + last2;
        last2 = last;
        last = current;
    }
}