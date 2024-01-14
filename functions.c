#include <stdio.h>

void print_big(int x);

int main() {
    int array[] = { 1, 11, 2, 22, 3, 33 };
    for (int i = 0; i < 6; i++) {
        print_big(array[i]);
    }
    return 0;
}

void print_big(int x) {
    if (x > 10) printf("%d is big\n", x);
}