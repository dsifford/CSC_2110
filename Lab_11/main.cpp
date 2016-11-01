/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 01.11.2016
 * Description: Program that demonstrates the extClockType derived class
 */
#include <iostream>
#include <cassert>
#include "extClockType.h"
using namespace std;

int main() {
    int h, m, s;
    extClockType c;

    assert(c.getTimeZone() == "UTC");

    c.getTime(h, m, s);
    assert(h == 0 && m == 0 && s == 0);

    c.setTime(5, 30, 12);
    c.getTime(h, m, s);
    assert(h == 5 && m == 30 && s == 12);

    extClockType c2(5, 10, 15, "EST");
    c2.getTime(h, m, s);
    assert(c2.getTimeZone() == "EST");
    assert(h == 5 && m == 10 && s == 15);

    cout << "==== Tests Passed ====" << endl;

    return 0;
}