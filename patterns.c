#include <stdio.h>

void half_number_pyramid(int height) {
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < r+1; ++c) {
            printf("%d ", c+1);
        }

        printf("\n");
    }
}

void inverted_half_pyramid(int height) {
    for (int r = 0; r < height; ++r) {
        for (int c = height-r; c > 0; --c) {
            printf("%d ", c);
        }

        printf("\n");
    }
}

void equilateral_pyramid(int height) {
    for (int r = 0; r < height; ++r) {
        for (int s1 = height - r - 1; s1 > 0; s1--) {
            printf("  ");
        }
        for (int s1 = -1; s1 < r; ++s1) {
            printf("%d ", s1+2);
        }
        for (int s2 = r - 1; s2 > -1; --s2) {
            printf("%d ", s2+1);
        }

        printf("\n");
    }
}

void full_pyramid_180_deg(int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            printf("%d", i+1);
        }
        printf("\n");
    }

    for (int i = height - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            printf("%d", i);
        }
        printf("\n");
    }
}

void hollow_pyramid(int height) {
    for (int i = height - 1; i > 0; --i) {
        for (int s1 = 0; s1 < i; ++s1) {
            printf(" ");
        }
        printf("*");
        for (int s2 = 0; s2 < (2*(height-1-i) - 1); ++s2) {
            printf(" ");
        }
        if (i != height-1)
            printf("*");

        printf("\n");
    }
    for (int i = 0; i < height; ++i) {
        printf("* ");
    }

    printf("\n");
}

void diamond_pyramid(int height) {
    for (int i = height - 1; i >= 0; --i) {
        for (int s1 = 0; s1 < i; ++s1) {
            printf(" ");
        }
        printf("*");
        for (int s2 = 0; s2 <= (2*(height-1-i) - 1); ++s2) {
            printf("*");
        }

        printf("\n");
    }

    for (int i = height; i > 0; --i) {
        for (int s1 = 0; s1 < height-i+1; ++s1) {
            printf(" ");
        }
        for (int s2 = (2*(i-1) - 1); s2 > 0 ; --s2) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");
}

int main() {
    half_number_pyramid(5);
    printf("\n");
    inverted_half_pyramid(5);
    printf("\n");
    equilateral_pyramid(5);
    printf("\n");
    full_pyramid_180_deg(5);
    printf("\n");
    hollow_pyramid(5);
    printf("\n");
    diamond_pyramid(5);
}