/**
 * Program Name: day-of-year.cpp
 * Developer: Derek P Sifford
 * Date: 27.09.2016
 * Description: Program to output day of year, correcting for leap year
 */
#include <iostream>
#include <string>
using namespace std;

int main() {

    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    string strYear, strMonth, strDay;
    int year, month, day, count = 0;

    cout << "Enter date without leading zeros (M-D-YYYY)" << endl;
    getline(cin, strMonth, '-');
    getline(cin, strDay, '-');
    getline(cin, strYear, '\n');

    year = stoi(strYear);
    month = stoi(strMonth);
    day = stoi(strDay);

    if ((year % 4 == 0 && year % 100 != 0) | (year % 100 == 0 && year % 400 == 0)) {
        daysPerMonth[1]++;
    }

    for (int i = 0; i < month - 1; i++) {
        count += daysPerMonth[i];
    }

    count += day;

    cout << "The day number for " << month << "-" << day << "-" << year << " is: " << count << endl;

    return 0;
}
