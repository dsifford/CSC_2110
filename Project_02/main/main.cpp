/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 04.11.2016
 * Description: Program to perform algebraic computations for lines in standard form
 */
#include <iostream>
#include <cassert>
#include <cmath>
#include "lineType.h"
using namespace std;

int main() {
    // a. If a line is nonvertical, then determine its slope.
    assert(LineType(2, -5, 9).slope() == 0.4);
    assert(isnan(LineType(-3, 0, -13).slope()));

    // b. If two lines are not parallel, then find the point of intersection.
    point expected = {.x = -5, .y = 7};
    point actual = LineType(2,3,11).intersection(LineType(-3, -4, -13));
    assert(actual.x == expected.x && actual.y == expected.y);
    actual = LineType(2, 3, 12).intersection(LineType(2, 3, 48));
    assert(isnan(actual.x) && isnan(actual.y));
    actual = LineType(1, 0, 2).intersection(LineType(22, 0, 53));
    assert(isnan(actual.x) && isnan(actual.y));

    // c. Overloads the stream insertion operator, <<, for easy output.
    LineType lineOne(1, 2, 3);
    cout << lineOne << endl;

    // d. Overloads the stream extraction operator, >>, for easy input.
    cout << "Enter three real numbers" << endl;
    cin >> lineOne;
    cout << lineOne << endl;

    // e. Overloads the assignment operator to copy a line into another line.
    LineType lineTwo(1, 2, 5);
    lineOne = lineTwo;
    cout
        << "Lines are now equal" << endl
        << "LineOne: " << lineOne << endl
        << "LineTwo: " << lineTwo << endl;

    // f. Overloads the unary operator +, as a member function, so that it returns true if a line is vertical; false otherwise.
    assert(+LineType(2, 0, 5));
    assert(+LineType(32, 0, 555));
    assert(!+LineType(4, -3, 34));
    assert(!+LineType(4, 7, 38));

    // g. Overloads the unary operator -, as a member function, so that it returns true if a line is horizontal; false otherwise.
    assert(-LineType(0, -4, 12));
    assert(-LineType(0, 5, 62));
    assert(!-LineType(3, 6, 23));
    assert(!-LineType(-4, 4, 28));

    // h. Overloads the operator ==, as a member function, so that it returns true if two lines are equal; false otherwise.
    assert(LineType(4, 5, 6) == LineType(4, 5, 6));
    assert(LineType(4, 5, 6) == LineType(-4, 5, 6) == false);
    assert(LineType(4, 5, 6) == LineType(4, -5, 6) == false);
    assert(LineType(4, 5, 6) == LineType(4, 5, -6) == false);
    assert(LineType(4, 5, 6) == LineType(2, 3, 19) == false);

    // i. Overloads the operator ||, as a member function, so that it returns true if two lines are parallel; false otherwise.
    assert(LineType(0, 4, 12) || LineType(0, -6, 34));
    assert(LineType(34, 0, 42) || LineType(3, 0, 12));
    assert(LineType(2, 3, 42) || LineType(2, 3, 12));
    assert((LineType(3, 5, 34) || LineType(3, 2, 15)) == false);

    // j. Overloads the operator &&, as a member function, so that it returns true if two lines are perpendicular; false otherwise.
    assert(LineType(0, 4, 12) && LineType(-6, 0, 34));
    assert(LineType(5, 0, 12) && LineType(0, 14, 24));
    assert(LineType(5, 0, 12) && LineType(0, 14, 24));
    assert(LineType(1, 1, 0) && LineType(1, -1, 0));
    assert((LineType(2, 4, 12) && LineType(4, 5, 9)) == false);

    cout << "==== TESTS PASSED ====" << endl;
    return 0;
}