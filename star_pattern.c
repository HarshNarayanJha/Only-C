#include <stdio.h>

/*

    *
   * *
  * * *
 * * * * 
* * * * *

*/

int main() {
    int h = 5;

    for (int i = 0; i < h; i++) {
        for (int s = h-1-i; s >= 0; s--) {
            printf(" ");
        }
        for (int j = 0; j < i+1; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// 5 0 4
// 5 1 3
// 5 2 2
// 5 3 1
// 5 4 0