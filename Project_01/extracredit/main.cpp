/**
 * Program Name: Project 1, Extra Credit
 * Developer: Derek P Sifford
 * Date: 01.10.2016
 * Description: Calculate sum and/or product of large integers
 */
#include <iostream>
#include <string>
#include <vector>
#include "largeintegers.h"
using namespace std;

int main() {

    largeIntegers a("175");
    largeIntegers b("156");

    a.add(b);

    a.print();

    return 0;
}
