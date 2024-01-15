#ifndef NUM_UTILS_H
#define NUM_UTILS_H

typedef int bool;

#ifndef true
    #define true 1
#endif
#ifndef false
    #define false 0
#endif

int ipow(int a, int n);

int get_num_digits(int num);

#endif