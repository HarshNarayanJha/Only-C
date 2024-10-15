// A(m, n)


// if m = 0
//     n + 1

// if m > 0 and n = 0
//     A(m-1, 1)

// if m > 0 and n > 0
//     A(m-1, A(m, n-1))


#include <stdio.h>

int main() {
    int ack(int, int);

    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    int a = ack(x, y);

    printf("The Ackerman is %d", a);
}

int ack(int m, int n) {
    if (m == 0) {
        return n + 1;
    }

    if ((m > 0) && (n == 0)) {
        return ack(m-1, 1);
    }

    if (m > 0 && n > 0) {
        return ack(m-1, ack(m, n-1));
    }
}