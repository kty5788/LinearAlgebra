//
//  Header.h
//  Linear-Algebra
//
//
//

#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>

class matrix {
private:
    size_t row;
    size_t col;
    std::vector<std::vector<double>> data;
    
public:
    matrix();
    ~matrix();
    matrix(size_t r, size_t c);
    matrix(std::initializer_list<std::initializer_list<double>> values);
    matrix& operator=(const matrix& other);
    matrix& operator=(std::initializer_list<std::initializer_list<double>> values);
    matrix operator+(const matrix& other) const;
    matrix operator-(const matrix& other) const;
    matrix operator*(double scalar) const;
    size_t getRow() const;
    size_t getCol() const;
    double getData(size_t r, size_t c) const;
    void size() const;
    void print() const;
    
};


matrix operator*(double scalar, const matrix& m);


#endif /* Header_h */
