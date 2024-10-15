#include <stdio.h>

int main() {
    int a[] = {2, 4, 5, 8, 1};

    int* ptr;
    ptr = a;
    while (ptr < a + sizeof(a) / sizeof(a[0])) {
        printf("%d %p\n", *ptr, ptr);
        ptr++;
    }
}