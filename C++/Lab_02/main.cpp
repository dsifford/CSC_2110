/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 15.09.2016
 * Description: Program for determining ROI
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    const double SERVICE_CHARGE = 0.015;
    double purchasePrice, sellingPrice, totalCharges, totalInvestment, totalSellAmount, deltaInvestment;
    int numSold;

    cout << "Enter # of shares sold: ";
    cin >> numSold;

    cout << "Enter purchase price per share: ";
    cin >> purchasePrice;

    cout << "Enter the selling price per share: ";
    cin >> sellingPrice;

    totalCharges = ((purchasePrice * SERVICE_CHARGE) + (sellingPrice * SERVICE_CHARGE) * numSold);
    totalInvestment = (purchasePrice * numSold) + ((purchasePrice * SERVICE_CHARGE) * numSold);
    totalSellAmount = (sellingPrice * numSold) - ((sellingPrice * SERVICE_CHARGE) * numSold);
    deltaInvestment = totalSellAmount - totalInvestment;

    cout
        << fixed << setprecision(2) << endl << endl << "==== Results ====" << endl
        << "Amount invested: $" << totalInvestment << endl
        << "Total charges: $" << totalCharges << endl
        << "Delta investment: $" << deltaInvestment << endl
        << "Total received after sale: $" << totalSellAmount << endl;


    return 0;
}
