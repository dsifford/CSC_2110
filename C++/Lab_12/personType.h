#ifndef PERSON_TYPE_H
#define PERSON_TYPE_H

#include <string>
#include <iostream>

using namespace std;

class personType {
    public:
        void print() const;
        // Function to output the first name and last name
        // in the form firstName lastName
        void setName(string first, string last);
        // Function to set firstName and lastName according
        // to the parameters.
        // Postcondition: firstName = first; lastName = last;
        void setFirstName(string first);
        // Function to set only the first name to the parameter
        // Postcondition: firstName
        void setLastName(string last);
        // Function to set only the last name to the parameter
        // Postcondition: lastName = last;
        void setMiddleName(string middle);
        // Function to set only the middle name to the parameter middle
        // Postcondition: middleName = middle;
        string getFirstName() const;
        // Function to return the first name.
        // Postcondition: The value of firstName is returned.
        string getMiddleName() const;
        // Function to return the middle name.
        // Postcondition: The value of middleName is returned.
        string getLastName() const;
        // Function to return the last name.
        // Postcondition: The value of lastName is returned.
        bool firstNameEquals(string test) const;
        // Function to check if firstName matches the string passed in
        // Postcondition: The truth value of the check is returned.
        bool lastNameEquals(string test) const;
        // Function to check if lastName matches the string passed in
        // Postcondition: The truth value of the check is returned.
        personType();
        // Defualt Constructor
        // sets firstName, middleName, lastName to null state.
        // Postcondition: firstName="";
        //			   middleName = "";
        //			   lastName = "";
        personType(string first, string middle, string last);
        // Constructor
        // Sets firstName, middleName, and lastName according to the parameters.

    private:
        string firstName;  // variable to store the first name.
        string lastName;  // variable to store the last name.
        string middleName; // variable to store the middle name.
};

#endif
