#ifndef MATRIX_TYPE_H
#define MATRIX_TYPE_H

#include <iostream>
#include <vector>
using namespace std;

struct dimensions {
    size_t rows; // number of rows
    size_t cols; // number of columns
    bool operator==(const dimensions &d) {
        return (rows == d.rows) && (cols == d.cols);
    };
    // Postcondition: return true if number of rows and columns of LHS
    // matches number of rows and columns of RHS, otherwise return false
    bool operator!=(const dimensions &d) {
        return (rows != d.rows) || (cols != d.cols);
    };
    // Postcondition: return true if number of rows OR number of columns on LHS
    // does not match number of rows OR number of columns on RHS, otherwise return false
};

class MatrixType {
    public:
        friend ostream &operator<<(ostream &os, const MatrixType &matrix);
        // Overloads the output stream operator to "pretty print" the value of
        // m to stdout
        // Postcondition: value of the matrix printed to std out
        const MatrixType &operator+(const MatrixType &matrix);
        // Precondition: LHS and RHS are two variables of MatrixType in which
        // the value of dims are equal.
        // Postcondition: A MatrixType equal to the sum of the LHS and RHS is returned
        // Note: If value of dims is not equal, an exception will be thrown
        const MatrixType &operator-(const MatrixType &matrix);
        // Precondition: LHS and RHS are two variables of MatrixType in which
        // the value of dims are equal.
        // Postcondition: A MatrixType equal to the difference of the RHS from the LHS is returned
        // Note: If value of dims is not equal, an exception will be thrown
        const MatrixType &operator*(const MatrixType &matrix);
        // Precondition: The LHS and RHS are two variables of MatrixType in which
        // cols of the LHS is equal to rows of the RHS
        // Postcondition: A MatrixType equal to the product of LHS * RHS is returned
        // Note: If precondition is not met, an exception will be thrown
        MatrixType(vector<vector<double>> matrix);
    private:
        dimensions dims; // Holder for value of columns and rows (see above definition)
        vector<vector<double>> m; // Value of the instance matrix
};

#endif
