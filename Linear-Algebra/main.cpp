#include <iostream>
#include <stdexcept>
#include <initializer_list>
template <class T> class matrix;

template<typename T>
matrix<T> operator*(T scalar, const matrix<T>& matrix) {
    return matrix * scalar;
}

template <class T> class matrix{
private:
    int row;
    int col;
    T** data;
    
public:
    matrix<T>() {
        row = 0;
        col = 0;
        data = nullptr;
    }
    
    ~matrix<T>() {
        if (data != nullptr) {
            for (int i = 0; i < row; i++) {
                delete[] data[i];
            }
            delete[] data;
        }
    }
    
    matrix<T>(int r, int c) {
        row = r;
        col = c;
        data = new T*[row];
        for (int i = 0; i < row; i++) {
            data[i] = new T[col];
            for (int j = 0; j < col; j++) {
                data[i][j] = 0;
            }
        }
    }
    
    matrix<T>(std::initializer_list<std::initializer_list<T>> values) {
        row = values.size();
        col = values.begin()->size();
        data = new T*[row];
        for (int i = 0; i < row; i++) {
            data[i] = new T[col];
            for (int j = 0; j < col; j++) {
                data[i][j] = 0;
            }
        }
    }
    
    matrix<T>& operator=(const matrix<T>& other) {
        if (this == &other) return *this;
        
        for (int i = 0; i < row; i++) {
            delete[] data[i];
        }
        delete[] data;
        
        row = other.row;
        col = other.col;
        
        data = new T*[row];
        for (int i = 0; i < row; i++) {
            data[i] = new T[col];
            for (int j = 0; j < col; j++) {
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }
    
    matrix<T>& operator=(std::initializer_list<std::initializer_list<T>> values) {
        if (row != values.size()) {
            throw std::runtime_error("Matrix size mismatch: cannot assign values of different size");
        }
        int check_row = col;
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
        
        data = new T*[row];
        int i = 0;
        for (auto& row_list : values) {
            data[i] = new T[col];
            int j = 0;
            for (auto& val : row_list) {
                data[i][j] = val;
                j++;
            }
            i++;
        }
        return *this;
    }
    
    matrix<T> operator+(const matrix<T>& other) const {
        if (row != other.row || col != other.col) {
            throw std::runtime_error("Matrix size mismatch for sum operation\n");
        }
        
        matrix<T> result(row,col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        
        return result;
    }
    
    matrix<T> operator-(const matrix<T>& other) const {
        if (row != other.row || col != other.col) {
            throw std::runtime_error("Matrix size mismatch for subtraction operation\n");
        }
        
        matrix<T> result(row,col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        
        return result;
    }
    
    matrix<T> operator*(T scalar) const {
        matrix<T> result(row,col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.data[i][j] = scalar * data[i][j];
            }
        }
        return result;
    }
    
    void size() const {
        std::cout << row << " * " << col << '\n';
    }
    
    void print() const {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
};

int main() {
    matrix<int> A(2,3);
    matrix<char> B(2,3);
    
    B.print();
    
    return 0;
}
