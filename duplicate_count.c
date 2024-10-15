#include <stdio.h>

int main() {
    int nums[] = {1, 4, 1, 3, 7, 2 ,6 , 7, 5, 3, 5, 10, 20, 50, 35, 35, 10, 20, 4, 6};
    int unq[20] = {};

    int c_unq = 0;

    for (int i = 0; i < 20; ++i) {
        if (c_unq == 0) {
            unq[c_unq++] = nums[i];
        } else {
            int in_already = 0;
            for (int j = 0; j < c_unq; ++j) {
                if (unq[j] == nums[i]) {
                    in_already = 1;
                }
            }

            if (in_already == 0) {
                unq[c_unq++] = nums[i];
            }
        }
    }

    printf("%3d\n", c_unq);
}