// Implementation file newClock.cpp

#include <iostream>
#include "clockType.h"

using namespace std;

clockType &operator++(clockType &c) {
    c.sec++;
    if (c.sec > 59) {
        c.sec = 0;
        c.min++;
        if (c.min > 59) {
            c.min = 0;
            c.hr++;
            if (c.hr > 23)
                c.hr = 0;
        }
    }
    return c;
}

clockType operator++(clockType &c, int amount) {
    clockType clk = c;

    if (amount != 0)
        c.sec += amount;
    else
        c.sec++;
    if (c.sec > 59) {
        c.sec = 0;
        c.min++;
        if (c.min > 59) {
            c.min = 0;
            c.hr++;
            if (c.hr > 23)
                c.hr = 0;
        }
    }
    return clk;
}

bool operator<(const clockType &lhs, const clockType &rhs) {
    return ((lhs.hr < rhs.hr) ||
            (lhs.hr == rhs.hr && lhs.min < rhs.min) ||
            (lhs.hr == rhs.hr && lhs.min == rhs.min &&
             lhs.sec < rhs.sec));
}

// Overload the equality operator.
bool clockType::operator==(const clockType &otherClock) const {
    return (hr == otherClock.hr && min == otherClock.min
            && sec == otherClock.sec);
}

// Overload the not equal operator.
bool clockType::operator!=(const clockType &otherClock) const {
    return (hr != otherClock.hr || min != otherClock.min
            || sec != otherClock.sec);
}

// Overload the less than or equal to operator.
bool clockType::operator<=(const clockType &otherClock) const {
    return ((hr < otherClock.hr) ||
            (hr == otherClock.hr && min < otherClock.min) ||
            (hr == otherClock.hr && min == otherClock.min &&
             sec <= otherClock.sec));
}

// Overload the greater than or equal to operator.
bool clockType::operator>=(const clockType &otherClock) const {
    return ((hr > otherClock.hr) ||
            (hr == otherClock.hr && min > otherClock.min) ||
            (hr == otherClock.hr && min == otherClock.min &&
             sec >= otherClock.sec));
}

// Overload the greater than operator.
bool clockType::operator>(const clockType &otherClock) const {
    return ((hr > otherClock.hr) ||
            (hr == otherClock.hr && min > otherClock.min) ||
            (hr == otherClock.hr && min == otherClock.min &&
             sec > otherClock.sec));
}

void clockType::setTime(int hours, int minutes, int seconds) {
    if (0 <= hours && hours < 24)
        hr = hours;
    else
        hr = 0;
    if (0 <= minutes && minutes < 60)
        min = minutes;
    else
        min = 0;
    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else
        sec = 0;
}

void clockType::getTime(int &hours, int &minutes,
                        int &seconds) const {
    hours = hr;
    minutes = min;
    seconds = sec;
}

// Constructor
clockType::clockType(int hours, int minutes, int seconds) {
    setTime(hours, minutes, seconds);
}

// Overload the stream insertion operator.
ostream &operator<<(ostream &osObject, const clockType &timeOut) {
    if (timeOut.hr < 10)
        osObject << '0';
    osObject << timeOut.hr << ':';

    if (timeOut.min < 10)
        osObject << '0';
    osObject << timeOut.min << ':';

    if (timeOut.sec < 10)
        osObject << '0';
    osObject << timeOut.sec;

    return osObject;  // return the ostream object
}

// overload the stream extraction operator
istream &operator>> (istream &is, clockType &timeIn) {
    char ch;

    is >> timeIn.hr;                          // Step a

    if (timeIn.hr < 0 || timeIn.hr >= 24)     // Step a
        timeIn.hr = 0;
    is.get(ch);           // Read and discard :. Step b

    is >> timeIn.min;                         // Step c

    if (timeIn.min < 0 || timeIn.min >= 60)   // Step c
        timeIn.min = 0;
    is.get(ch);           // Read and discard :. Step d

    is >> timeIn.sec;                         // Step e

    if (timeIn.sec < 0 || timeIn.sec >= 60)   // Step e
        timeIn.sec = 0;
    return is;                                // Step f
}