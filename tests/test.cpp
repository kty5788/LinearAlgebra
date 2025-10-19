//
//  test.cpp
//  Linear-Algebra
//
//  Created by 강태윤 on 10/18/25.
//

#include <mylib/Matrix.h>

int main() {
    matrix A{{1,2,3},{4,5,6}};
    matrix B{{1,2,3}};
    matrix C{{1,2,3}};
    
    
    double x = dot(B,C);
    std::cout << x << '\n';
    
    
    return 0;
}
