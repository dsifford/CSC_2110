/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: DD.11.2016
 * Description: Program implementing MatrixType
 */
#include <iostream>
#include <vector>
#include "matrixType.h"
using namespace std;

typedef vector<vector<double>> matrix;

void sum();
void difference();
void multiply();

int main() {
    sum();
    difference();
    multiply();
    return 0;
}

void sum() {
    matrix a = {
        {12, 19, 28},
        {34, 5, 62},
        {121, 5, 24},
        {15, 9, 75}
    };
    matrix b = {
        {44, 53, 21},
        {73, 9, 101},
        {-19, 5, -44},
        {6, -155, 64}
    };
    MatrixType A(a);
    MatrixType B(b);

    cout
        << "A + B =" << endl
        << A + B << endl;
}

void difference() {
    matrix a = {
        {12, 19, 28},
        {34, 5, 62},
        {121, 5, 24},
        {15, 9, 75}
    };
    matrix b = {
        {44, 53, 21},
        {73, 9, 101},
        {-19, 5, -44},
        {6, -155, 64}
    };
    MatrixType A(a);
    MatrixType B(b);

    cout
        << "A - B =" << endl
        << A - B << endl;
}

void multiply() {
    matrix a = {
        {1, 2, 3},
        {4, 5, 6}
    };
    matrix b = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    MatrixType A(a);
    MatrixType B(b);

    cout
        << "A * B =" << endl
        << A * B << endl;
}