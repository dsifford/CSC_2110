/**
 * Program Name: problem_04.cpp
 * Developer: Derek P Sifford
 * Date: 06.09.2016
 * Description: Program which determines if a triange is a right triangle
 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double side1, side2, side3;

    cout << "Enter the length of the hypotenuse: ";
    cin >> side1;

    cout << "Enter the length of the base: ";
    cin >> side2;

    cout << "Enter the length of the height: ";
    cin >> side3;

    if (pow(side1, 2) == (pow(side2, 2) + pow(side3, 2))) {
        cout << "The triangle is a right triangle" << endl;
    }
    else {
        cout << "The triangle is not a right triangle" << endl;
    }

    return 0;
}
