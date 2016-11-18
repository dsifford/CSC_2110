#ifndef DAY_TYPE_H
#define DAY_TYPE_H

#include <string>
using namespace std;

class dayType {
public:
    enum days { SUN, MON, TUES, WED, THURS, FRI, SAT };
    void set(days d);
    string get() const;
    string tomorrow() const;
    string yesterday() const;
    string addDays(int n) const;
    void print() const;
    dayType();
    dayType(days d);
    
private:
    string const dayMap[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    days day;
};

#endif