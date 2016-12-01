#include <string>
#include "tornadoException.h"
using namespace std;

tornadoException::tornadoException() {
    err = "Tornado: Take cover immediately!";
}

tornadoException::tornadoException(int m) {
    err = "Tornado: ";
    err += to_string(m);
    err += " miles away and approaching!";
}

string tornadoException::what() const {
    return err;
}