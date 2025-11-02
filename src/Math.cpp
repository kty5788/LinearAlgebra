#include <mylib/Math.h>

double sqrt(double k, double prev_value) {
    int iter = 7;
    while (iter > 0) {
        prev_value = (prev_value + (k/prev_value))/2;
        iter--;
    }
    return prev_value;
}

double cmin(double A, double B) {
    if (A > B) {
        return B;
    }
    else {
        return A;
    }
}

