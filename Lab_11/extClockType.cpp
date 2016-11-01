#include <iostream>
#include <string>
#include "extClockType.h"
using namespace std;

void extClockType::setTimeZone(string t) {
    tz = t;
}

string extClockType::getTimeZone() const {
    return tz;
}

extClockType::extClockType(int h, int m, int s, string z) : clockType(h, m, s) {
    tz = z;
}

extClockType::extClockType() {
    tz = "UTC";
}
