#include <stdio.h>

int main() {
    int n;
    printf("How many questions? ");
    scanf("%d", &n);

    int score;
    score = 0;

    printf("Enter T or F: \n");
    for (int i = 0; i < n; ++i) {
        char c;
        do {
            printf("> ");
            c = getchar();
        } while (c != 'T' || c  != 'F' || c != ' ');

        switch (c)
        {
            case 'T':
                score += 2;
                break;
            case 'F':
                score += 1;
                break;
            case ' ':
                break;
            default:
                break;
        }
    }

    printf("Score is: %d", score);
}