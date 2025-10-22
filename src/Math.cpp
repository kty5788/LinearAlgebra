#include <mylib/Math.h>

double sqrt(double k, double prev_value, int iter) {
    if (iter == 1) prev_value = k;
    if (iter != 7) {
        sqrt(k, (prev_value + (k/prev_value))/2, iter+1);
    }
    else {
        k = prev_value;
        return k;
    }
    return -1;
}

