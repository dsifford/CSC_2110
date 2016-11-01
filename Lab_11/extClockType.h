#ifndef EXT_CLOCK_TYPE_H
#define EXT_CLOCK_TYPE_H

#include "clockType.h"
#include <string>
using namespace std;

class extClockType : public clockType {
    public:
        void setTimeZone(string t);
        // Function to set the time zone
        // Postcondition: tz = t
        string getTimeZone() const;
        // Function to return the time zone
        // Postcondition: tz unchanged, tz value returned
        extClockType(int h, int m, int s, string z);
        // Constructor with params
        // The time is set to h:m:s, timezone set to z
        // Postcondition: hr=h, min=m, sec=s, tz=z
        extClockType();
        // Default constructor
        // The time is set to 00:00:00, TZ set to UTC
        // Postcondition: hr=0, min=0, sec=0, tz=UTC
    private:
        string tz; // Variable to store the timezone
};

#endif