#include <mylib/Matrix.h>

matrix::matrix() {
    std::vector<std::vector<double>> data;
    row = 0;
    col = 0;
}
    
matrix::~matrix() {
    data.clear();
}
    
matrix::matrix(size_t r, size_t c) {
    row = r;
    col = c;
    
    data.resize(row);
    for (size_t i = 0; i < row; i++) {
        data[i].resize(col,0);
    }
}
    
matrix::matrix(std::initializer_list<std::initializer_list<double>> values) {
    row = values.size();
    col = values.begin()->size();
    
    data.resize(row);
    for (size_t i = 0; i < row; i++) {
        data[i].resize(col,0);
    }
    
    int i = 0;
    for (auto& row_list : values) {
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
    
    row = other.row;
    col = other.col;
    
    for (int i = 0; i < row; i++) {
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
    
    row = values.size();
    col = values.begin()->size();
    
    data.resize(row);
    for (size_t i = 0; i < row; i++) {
        data[i].resize(col,0);
    }
    
    int i = 0;
    for (auto& row_list : values) {
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
        std::cout << "[";
        for (int j = 0; j < col; j++) {
            std::cout << " " << data[i][j];
        }
        std::cout << " ]" << '\n';
    }
    std::cout << '\n';
}

size_t matrix::getRow() const {
    return row;
}

size_t matrix::getCol() const {
    return col;
}

double matrix::getData(size_t r, size_t c) const {
    return data[r][c];
}

matrix operator*(double scalar, const matrix& m) {
    return m * scalar;
}

matrix GaussianElimination(matrix& m) {
    size_t r = m.getRow();
    size_t c = m.getCol();
    
    matrix result(r,c);
    result = m;
    
    
    /*
    size_t changed_time = 0;
    for (size_t i = 0; i < r; i++) {
        if (result.data[i][changed_time] == 0) {
            // 기본 행연산 row operation -> maybe This part might be a void function.
            for (size_t col = 0; col < c; col++) {
                double temp = result.data[i][col];
                result.data[i][col] = result.data[changed_time][col];
                result.data[changed_time][col] = temp;
            }
        }
    }
     */
    
    size_t standard = 0;
    double mul;
    while (standard < c) {
        for (size_t i = standard; i < r; i++) {
            if (i != standard) {
                if (result.data[i][standard] == 0) {
                    mul = 0;
                }
                else {
                    mul = result.data[i][standard] / result.data[standard][standard];
                }
                
                for (size_t j = standard; j < c; j++) {
                    result.data[i][j] = result.data[i][j] - mul * result.data[standard][j];
                }
            }
        }
        standard++;
    }
    
    return result;
}
