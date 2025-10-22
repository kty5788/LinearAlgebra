#include <mylib/Matrix.h>
#include <mylib/Math.h>
#include <mylib/Vector.h>

int main() {
    matrix A{{1,2,3},{4,5,6}};
    matrix B{{1,1,2}};
    matrix C{{1,2,3}};
    
    
    double x = dot(B,C);
    std::cout << x << '\n';
    std::cout << norm(B) << '\n';
    
    /*
    C = normalize(C);
    C.print();
     */
    
    A.print();
    
    std::cout << dist(B,C) << '\n';
    
    std::cout << deg(B,C) << '\n';
    
    
    return 0;
}
