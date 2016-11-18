
#include "personType.h"
#include <iostream>
#include <string>
using namespace std;

void personType::print() const {
    cout << firstName << " " << lastName << endl;
}

void personType::setName(string first, string last) {
    firstName = first;
    lastName = last;
}

void personType::setFirstName(string first) {
    firstName = first;
}

void personType::setMiddleName(string middle) {
    middleName = middle;
}

void personType::setLastName(string last) {
    lastName = last;
}

string personType::getFirstName() const {
    return firstName;
}

string personType::getMiddleName() const {
    return middleName;
}

string personType::getLastName() const {
    return lastName;
}

bool personType::firstNameEquals(string test) const {
    return firstName == test;
}

bool personType::lastNameEquals(string test) const {
    return lastName == test;
}

personType::personType() {
    firstName = "";
    middleName = "";
    lastName = "";
}

personType::personType(string first, string middle, string last) {
    firstName = first;
    middleName = middle;
    lastName = last;
}