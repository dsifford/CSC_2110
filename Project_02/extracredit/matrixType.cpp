#include <iostream>
#include "matrixType.h"
using namespace std;

ostream &operator<<(ostream &os, const MatrixType &matrix) {
    for (auto i : matrix.m) {
        for (auto j : i)
            os << j << " ";
        os << endl;
    }
    return os;
}

MatrixType::MatrixType(vector<vector<double>> matrix) {
    dims.cols = 0;
    for (auto i : matrix) {
        if (i.size() > dims.cols)
            dims.cols = i.size();
        dims.rows++;
    }
    for (size_t i = 0; i < matrix.size(); i++)
        matrix[i].resize(dims.cols, 0);
    m = matrix;
}

const MatrixType &MatrixType::operator+(const MatrixType &matrix) {
    if (this->dims != matrix.dims)
        throw out_of_range("Matrix dimentions must be equal");
    for (size_t i = 0; i < this->dims.rows; i++) {
        for (size_t j = 0; j < this->dims.cols; j++) {
            this->m[i][j] += matrix.m[i][j];
        }
    }
    return *this;
}

const MatrixType &MatrixType::operator-(const MatrixType &matrix) {
    if (this->dims != matrix.dims)
        throw out_of_range("Matrix dimentions must be equal");
    for (size_t i = 0; i < this->dims.rows; i++)
        for (size_t j = 0; j < this->dims.cols; j++)
            this->m[i][j] -= matrix.m[i][j];
    return *this;
}

const MatrixType &MatrixType::operator*(const MatrixType &matrix) {
    if (this->dims.cols != matrix.dims.rows)
        throw out_of_range("Columns of LHS must match rows of RHS");
    vector<vector<double>> product;
    product.resize(matrix.dims.cols, vector<double>(this->dims.rows, 0));
    for (size_t leftRow = 0; leftRow < this->dims.rows; leftRow++)
        for (size_t rightCol = 0; rightCol < matrix.dims.cols; rightCol++)
            for (size_t leftCol = 0; leftCol < this->dims.cols; leftCol++)
                product[leftRow][rightCol] += this->m[leftRow][leftCol] * matrix.m[leftCol][rightCol];
    this->m = product;
    return *this;
}