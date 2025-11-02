#include <mylib/Matrix.h>
#include <mylib/Math.h>
#include <mylib/Vector.h>

int main() {
    matrix A{{1,2,3,4},{2,3,4,5},{3,4,5,6}};
    matrix B{{0,0,0,0},{1,0,3,4},{5,6,7,8}};
    
    A = GaussianElimination(A);
    B = GaussianElimination(B);
    
    A.print();
    B.print();
    
    return 0;
}
