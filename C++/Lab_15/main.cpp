/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 17.11.2016
 * Description: Create and test a Money class
 */
#include <iostream>
#include <cassert>
#include "money.h"
using namespace std;

int main() {
    Money m1;
    Money m2(12, 50);

    assert(m1.getDollars() == 0);
    assert(m1.getCents() == 0);
    assert(m1.value() == 0);

    assert(m2.getDollars() == 12);
    assert(m2.getCents() == 50);
    assert(m2.value() == 12.50);

    m1.setDollars(41);
    m1.setCents(98);

    assert(m1.value() == 41.98);

    cout << "==== TESTS PASSED ====" << endl;

    return 0;
}