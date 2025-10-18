#include <mylib/Matrix.h>

matrix::matrix() {
    row = 0;
    col = 0;
    data = nullptr;
}
    
matrix::~matrix() {
    if (data != nullptr) {
        for (int i = 0; i < row; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
}
    
matrix::matrix(size_t r, size_t c) {
    row = r;
    col = c;
    data = new double*[row];
    for (int i = 0; i < row; i++) {
        data[i] = new double[col];
        for (int j = 0; j < col; j++) {
            data[i][j] = 0;
        }
    }
}
    
matrix::matrix(std::initializer_list<std::initializer_list<double>> values) {
    row = values.size();
    col = values.begin()->size();
    data = new double*[row];
    
    int i = 0;
    for (auto& row_list : values) {
        data[i] = new double[col];
        int j = 0;
        for (auto& val : row_list) {
            data[i][j] = val;
            j++;
        }
        i++;
    }
}
    
matrix& matrix::operator=(const matrix& other) {
    if (this == &other) return *this;
    
    for (int i = 0; i < row; i++) {
        delete[] data[i];
    }
    delete[] data;
    
    row = other.row;
    col = other.col;
    
    data = new double*[row];
    for (int i = 0; i < row; i++) {
        data[i] = new double[col];
        for (int j = 0; j < col; j++) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}
    
matrix& matrix::operator=(std::initializer_list<std::initializer_list<double>> values) {
    if (row != values.size()) {
        throw std::runtime_error("Matrix size mismatch: cannot assign values of different size");
    }
    size_t check_row = col;
    int r = 0;
    for (auto& rlist : values) {
        if (rlist.size() != check_row) {
            throw std::runtime_error("Matrix size mismatch: cannot assign values of different size");
        }
        r++;
    }
    
    if (data != nullptr) {
        for (int i = 0; i < row; i++)
            delete[] data[i];
        delete[] data;
    }
    
    row = values.size();
    col = values.begin()->size();
    
    data = new double*[row];
    int i = 0;
    for (auto& row_list : values) {
        data[i] = new double[col];
        int j = 0;
        for (auto& val : row_list) {
            data[i][j] = val;
            j++;
        }
        i++;
    }
    return *this;
}
    
matrix matrix::operator+(const matrix& other) const {
    if (row != other.row || col != other.col) {
        throw std::runtime_error("Matrix size mismatch for sum operation\n");
    }
    
    matrix result(row,col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    
    return result;
}
    
matrix matrix::operator-(const matrix& other) const {
    if (row != other.row || col != other.col) {
        throw std::runtime_error("Matrix size mismatch for subtraction operation\n");
    }
    
    matrix result(row,col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    
    return result;
}
    
matrix matrix::operator*(double scalar) const {
    matrix result(row,col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.data[i][j] = scalar * data[i][j];
        }
    }
    return result;
}
    
    
void matrix::size() const {
    std::cout << row << " * " << col << '\n';
}
    
void matrix::print() const {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

matrix operator*(double scalar, const matrix& m) {
    return m * scalar;
}
