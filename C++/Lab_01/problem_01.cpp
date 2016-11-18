/**
 * Program Name: problem_01.cpp
 * Developer: Derek P Sifford
 * Date: 06.09.2016
 * Description: Receive time in seconds; return elapsed time in HH:MM:SS
 */
#include <iostream>
using namespace std;

int main() {

    int hours = 0, mins = 0, secs = 0;

    cout << "Enter time in seconds: ";
    cin >> secs;

    while (secs >= 60) {
        mins++;
        secs = secs - 60;
    }

    while (mins >= 60) {
        hours++;
        mins = mins - 60;
    }

    printf("The elapsed time is %02d:%02d:%02d", hours, mins, secs);

    return 0;
}
