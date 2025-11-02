#include <mylib/Vector.h>
#include <mylib/Math.h>

double dist(const matrix& m1, const matrix& m2) {
    return norm(m1-m2);
}

double deg(const matrix& u, const matrix& v) {
    double cos = dot(u,v) / (norm(u) * norm(v));
    return std::acos(cos);
}

double norm(const matrix& m) {
    if (m.getRow() != 1) {
        throw std::runtime_error("norm can be used in 1 row vector");
    }
    else {
        double d = 0;
        for(int i = 0; i < m.getCol(); i++) {
            d += m.getData(0, i) * m.getData(0, i);
        }
        
        return sqrt(d,1);
    }
}

double dot(const matrix& m1, const matrix& m2) {
    if (m1.getRow() != 1 || m2.getRow() != 1) {
        throw std::runtime_error("dot product can be used in vector, not matrix");
    }
    else if (m1.getCol() != m2.getCol()) {
        throw std::runtime_error("dot: size mismatch");
    }
    else {
        int d = 0;
        for (int i = 0; i < m1.getCol(); i++) {
            d += m1.getData(0, i) * m2.getData(0, i);
        }
        return d;
    }
}

matrix normalize(const matrix& m) {
    return (1/norm(m)) * m;
}
