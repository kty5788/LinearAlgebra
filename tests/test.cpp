//
//  test.cpp
//  Linear-Algebra
//
//  Created by 강태윤 on 10/18/25.
//

#include <mylib/Matrix.h>

int main() {
    matrix A{{1,2,3},{4,5,6}};
    matrix B{{1,1,1},{2,2,2}};
    matrix C(2,3);
    matrix D(2,3);
    
    C = A + B;
    D = 3 * C;
    
    C.print();
    D.print();
    
    return 0;
}
