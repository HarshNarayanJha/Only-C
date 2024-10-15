#include <stdio.h>
#include <string.h>

int main() {
    FILE* nums;
    FILE* odds;
    FILE* evens;

    nums = fopen("DATA", "r");
    if (nums == NULL) {
        printf("Err opening file %s\n", "DATA");
        return -1;
    }

    odds = fopen("ODD", "w");
    if (odds == NULL) {
        printf("Err opening file %s\n", "ODD");
        return -1;
    }

    evens = fopen("EVEN", "w");
    if (evens == NULL) {
        printf("Err opening file %s\n", "EVEN");
        return -1;
    }

    int i;
    while (fscanf(nums, "%d", &i) !=  EOF) {
        if (i % 2 == 0) {
            fprintf(evens, "%d ", i);
        } else {
            fprintf(odds, "%d ", i);
        }
    }

    fclose(nums);
    fclose(odds);
    fclose(evens);

    return 0;
}