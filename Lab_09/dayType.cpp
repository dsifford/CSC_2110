/**
 * Program Name: dayType.cpp
 * Developer: Derek P Sifford
 * Date: 23.10.2016
 * Description: Implementation of class dayType
 */

#include "dayType.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Default constructor. Sets day to sunday.
 */
dayType::dayType() {
    day = SUN;
}

dayType::dayType(days d) {
    day = d;
}

void dayType::set(days d) {
    day = d;
}

void dayType::print() const {
    cout << get() << endl;
}

string dayType::get() const {
    return dayMap[day];
}

string dayType::tomorrow() const {
    if (day == SAT)
        return dayMap[SUN];
    return dayMap[day + 1];
}

string dayType::yesterday() const {
    if (day == SUN)
        return dayMap[SAT];
    return dayMap[day - 1];
}

string dayType::addDays(int n) const {
    days d = day;
    for (size_t i = 0; i < n; i++) {
        if (d == SAT) {
            d = SUN;
            continue;
        }
        d = static_cast<days>(d + 1);
    }
    return dayMap[d];
}