
#ifndef Vector_h
#define Vector_h

#include <mylib/Matrix.h>

double norm(const matrix& m);
double dot(const matrix& m1, const matrix& m2);
double dist(const matrix& m1, const matrix& m2);
double deg(const matrix& m1, const matrix& m2);
matrix normalize(const matrix& m);

#endif /* Vector_h */
