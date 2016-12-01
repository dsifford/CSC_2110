/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 01.12.2016
 * Description: Tests for exception class tornadoException
 */
#include <iostream>
#include <cassert>
#include "tornadoException.h"
using namespace std;

int main() {
    try {
        throw tornadoException();
    }
    catch(tornadoException e) {
        assert(e.what() == "Tornado: Take cover immediately!");
    }
    catch(...) {
        cout << "~~~~ TESTS FAILED ~~~~" << endl;
        exit(EXIT_FAILURE);
    }

    try {
        throw tornadoException(5);
    }
    catch(tornadoException e) {
        assert(e.what() == "Tornado: 5 miles away and approaching!");
    }
    catch(...) {
        cout << "~~~~ TESTS FAILED ~~~~" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "==== TESTS PASSED ====" << endl;
    return 0;
}