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

int main() {
    vector<vector<double>> x = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<double>> y = {{7, 8}, {9, 10}, {11, 12}};
    MatrixType a(x);
    MatrixType b(y);
    cout << a << endl;
    cout << b << endl;
    cout << a * b << endl;

    return 0;
}
