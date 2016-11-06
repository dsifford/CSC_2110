#ifndef MATRIX_TYPE_H
#define MATRIX_TYPE_H

#include <iostream>
#include <vector>
using namespace std;

struct dimensions {
    size_t rows;
    size_t cols;
    bool operator==(const dimensions &d) {
        return (rows == d.rows) && (cols == d.cols);
    };
    bool operator!=(const dimensions &d) {
        return (rows != d.rows) || (cols != d.cols);
    };
};

class MatrixType {
    public:
        friend ostream &operator<<(ostream &os, const MatrixType &matrix);
        const MatrixType &operator+(const MatrixType &matrix);
        const MatrixType &operator-(const MatrixType &matrix);
        const MatrixType &operator*(const MatrixType &matrix);
        MatrixType(vector<vector<double>> matrix);
    private:
        dimensions dims;
        vector<vector<double>> m;
};

#endif
