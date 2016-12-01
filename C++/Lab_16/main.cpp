/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 01.12.2016
 * Description: Overload pre- and post-increment operators as well as
 *   less than operator for clockType as non-member functions
 */
#include <iostream>
#include <cassert>
#include "clockType.h"
using namespace std;

int main() {
    clockType a(1, 2, 3);
    clockType b(4, 5, 6);

    // Less than operator tests
    assert(a < b);

    a.setTime(1, 1, 1);
    b.setTime(1, 1, 2);
    assert(a < b);

    a.setTime(1, 1, 2);
    b.setTime(1, 2, 2);
    assert(a < b);

    a.setTime(1, 2, 2);
    b.setTime(2, 2, 2);
    assert(a < b);

    a.setTime(2, 2, 2);
    b.setTime(2, 2, 2);
    assert(a < b == false);

    // Pre-increment tests
    int hr, min, sec;
    ++a;
    a.getTime(hr, min, sec);
    assert(sec == 3 && min == 2 && hr == 2);

    a.setTime(1, 1, 59);
    ++a;
    a.getTime(hr, min, sec);
    assert(sec == 0 && min == 2 && hr == 1);

    a.setTime(1, 59, 59);
    ++a;
    a.getTime(hr, min, sec);
    assert(sec == 0 && min == 0 && hr == 2);

    a.setTime(23, 59, 59);
    ++a;
    a.getTime(hr, min, sec);
    assert(sec == 0 && min == 0 && hr == 0);

    // Post-increment tests
    a.setTime(2, 2, 2);
    a++;
    a.getTime(hr, min, sec);
    assert(sec == 3 && min == 2 && hr == 2);

    a.setTime(1, 1, 59);
    a++;
    a.getTime(hr, min, sec);
    assert(sec == 0 && min == 2 && hr == 1);

    a.setTime(1, 59, 59);
    a++;
    a.getTime(hr, min, sec);
    assert(sec == 0 && min == 0 && hr == 2);

    a.setTime(23, 59, 59);
    a++;
    a.getTime(hr, min, sec);
    assert(sec == 0 && min == 0 && hr == 0);

    operator++(a, 30);
    a.getTime(hr, min, sec);
    assert(sec == 30 && min == 0 && hr == 0);

    cout << "==== TESTS PASSED ====" << endl;
    return 0;
}