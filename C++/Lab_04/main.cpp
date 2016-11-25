/**
 * Program Name: lab_04.cpp
 * Developer: Derek P Sifford
 * Date: 23.09.2016
 * Description: Program that outputs roots of a quadratic equation
 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, discriminant;

    cout << "Enter value of 'a': ";
    cin >> a;

    cout << "Enter value of 'b': ";
    cin >> b;

    cout << "Enter value of 'c': ";
    cin >> c;

    discriminant = pow(b, 2) - (4 * a * c);

    if (discriminant < 0) {
        cout << "Equation has two complex roots" << endl;
        return 0;
    }
    if (discriminant == 0) {
        cout << "Equation has one real root" << endl;
        cout << "Root: " << -b / (2 * a) << endl;
        return 0;
    }
    cout << "Equation has two real roots" << endl;
    cout
        << "Roots: "
        << (-b + sqrt(discriminant)) / (2 * a) << ", "
        << (-b - sqrt(discriminant)) / (2 * a) << endl;

    return 0;
}
