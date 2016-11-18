/**
 * Program Name: problem_02.cpp
 * Developer: Derek P Sifford
 * Date: 06.09.2016
 * Description: Outputs profit/cost margins for a milk corporation.
 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    const double COST = 0.38;
    const double PROFIT = 0.27;
    const double LITERS_PER_CARTON = 3.78;

    double liters, cost, profit, cartons;

    cout << "Enter number of liters produced: ";
    cin >> liters;

    cartons = static_cast<int>(liters / LITERS_PER_CARTON);
    cost = liters * COST;
    profit = liters * PROFIT;

    cout << "Number of milk cartons needed: " << round(cartons) << endl;
    cout << "Cost of producing milk: " << cost << endl;
    cout << "Profit of producing milk: " << profit << endl;

    return 0;
}
