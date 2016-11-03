/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 03.11.2016
 * Description: Program that extends the class personType
 */
#include <iostream>
#include <cassert>
#include <string>
#include "personType.h"
using namespace std;

int main() {
    personType p;

    assert(p.getFirstName() == "" && p.getLastName() == "" && p.getMiddleName() == "");
    p.setFirstName("John");
    assert(p.getFirstName() == "John" && p.getLastName() == "" && p.getMiddleName() == "");
    p.setLastName("Doe");
    assert(p.getFirstName() == "John" && p.getLastName() == "Doe" && p.getMiddleName() == "");
    p.setMiddleName("Deere");
    assert(p.getFirstName() == "John" && p.getLastName() == "Doe" && p.getMiddleName() == "Deere");

    personType p2("First", "Middle", "Last");
    assert(p2.getFirstName() == "First" && p2.getLastName() == "Last" && p2.getMiddleName() == "Middle");
    assert(!p2.firstNameEquals("Bob"));
    assert(!p2.firstNameEquals("John"));
    assert(p2.firstNameEquals("First"));
    assert(!p2.lastNameEquals("Doe"));
    assert(!p2.lastNameEquals("Smith"));
    assert(p2.lastNameEquals("Last"));

    cout << "==== Tests Passed ====";
    return 0;
}