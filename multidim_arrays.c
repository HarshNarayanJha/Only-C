#include <stdio.h>

int main() {

    int grades[2][5];

    float average;

    grades[0][0] = 80;
    grades[0][1] = 70;
    grades[0][2] = 65;
    grades[0][3] = 89;
    grades[0][4] = 90;

    grades[1][0] = 85;
    grades[1][1] = 80;
    grades[1][2] = 80;
    grades[1][3] = 82;
    grades[1][4] = 87;

    for (int i = 0; i < 2; ++i) {
        float average = 0;
        for (int j = 0; j < 5; ++j) {
            average += grades[i][j];
        }

        average = average / 5;

        printf("The average marks obtained in subject %d is: %.2f\n", i, average);
    }

    return 0;
}