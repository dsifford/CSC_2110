/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 27.10.2016
 * Description: Extension of clockType class to modify portions of the time
 */

#include <iostream>
#include <cassert>
#include "clockType.h"
using namespace std;

int main() {
    clockType c(6, 7, 8);
    assert(c.getHours() == 6);
    assert(c.getMinutes() == 7);
    assert(c.getSeconds() == 8);

    c.setHours(1);
    c.setMinutes(2);
    c.setSeconds(3);
    assert(c.getHours() == 1);
    assert(c.getMinutes() == 2);
    assert(c.getSeconds() == 3);

    cout << "==== Tests Passed ====" << endl;
    return 0;
}
