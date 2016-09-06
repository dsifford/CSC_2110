/**
 * Program Name: problem_03.cpp
 * Developer: Derek P Sifford
 * Date: 06.09.2016
 * Description: Calculates ticket sales for a football stadium
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    double numTickets, price, totalTickets = 0, totalSales = 0;
    string line;
    fstream input;

    input.open("./tickets.txt");

    while (input >> price >> numTickets) {
        totalTickets += numTickets;
        totalSales += price * numTickets;
    }

    input.close();

    cout << fixed << setprecision(2)
    << "Total tickets sold: " << totalTickets << endl
    << "Total sales: " << totalSales << endl;

    return 0;
}
