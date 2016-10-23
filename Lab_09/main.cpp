/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 23.10.2016
 * Description: dayType class implementation
 */
#include <iostream>
#include <cassert>
#include "dayType.h"
using namespace std;

void test();

int main() {
    
    test();
    
    return 0;
}

void test() {
    
    dayType d;
    
    assert(d.get() == "Sunday");
    assert(d.tomorrow() == "Monday");
    assert(d.yesterday() == "Saturday");
    assert(d.addDays(7) == "Sunday");
    assert(d.addDays(18) == "Thursday");
    assert(d.addDays(428) == "Monday");
    assert(d.get() == "Sunday");
    
    d.set(dayType::THURS);
    assert(d.get() == "Thursday");
    assert(d.tomorrow() == "Friday");
    assert(d.yesterday() == "Wednesday");
    
    d.set(dayType::SAT);
    assert(d.get() == "Saturday");
    assert(d.tomorrow() == "Sunday");
    assert(d.yesterday() == "Friday");
    assert(d.addDays(1529) == "Tuesday");
    
    dayType e(dayType::TUES);
    assert(e.get() == "Tuesday");
    
    cout << "==== Tests Passed ====";
    
}