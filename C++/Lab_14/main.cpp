#include <iostream>
#include <cassert>
#include "temp.h"
using namespace std;

int main() {
    Temperature t;

    t.setTempKelvin(273.15);

    // "get" tests
    assert(t.get(K) == 273.15);
    assert(t.get(C) == 0);
    assert(t.get(F) == 32);

    // setTempCelcius tests
    t.setTempCelcius(32);
    assert(t.get(K) == 305.15);
    assert(t.get(C) == 32);

    // setTempFahrenheit tests
    t.setTempFahrenheit(32);
    assert(t.get(F) == 32);
    assert(t.get(C) == 0);
    assert(t.get(K) == 273.15);

    cout << "==== TESTS PASSED ====" << endl;

    return 0;
}