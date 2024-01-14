#include <stdio.h>

int main() {
    int a = 10, b = 6, c = 8;

    int largest = a;

    if (b > largest) {
        largest = b;
    }

    if (c > largest) {
        largest = c;
    }

    printf("%d", largest);
}