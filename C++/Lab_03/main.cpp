/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 20.09.2016
 * Description: Lab 3
 */
#include <iostream>
#include <iomanip>
using namespace std;

int problemOne();
void calculateFarmRevenue(double &totalRevenue, double &totalCost, int percentArea, int landArea);

int problemTwo();

int main() {
    problemOne();
    problemTwo();
    return 0;
}

int problemOne() {
    int
        landArea,
        numVegetables,
        percentArea = 100;

    double
        totalRevenue = 0,
        totalCost = 0;

    cout << "Enter the total farm area in acres: ";
    cin >> landArea;

    do {
        cout << "Enter number of vegetables that you'd like to grow (1 or 2): ";
        cin >> numVegetables;
    } while (numVegetables != 1 && numVegetables != 2);

    if (numVegetables == 2) {
        do {
            cout << "Enter the percent area for vegetable #1: ";
            cin >> percentArea;
        } while(percentArea > 100 || percentArea < 0);
        cout << "Calculating profit margins for vegetable #1 using " << percentArea << "% land area" << endl;
        calculateFarmRevenue(totalRevenue, totalCost, percentArea, landArea);
        cout << "Calculating profit margins for vegatable #2 using " << (100 - percentArea) << "% land area" << endl;
        calculateFarmRevenue(totalRevenue, totalCost, 100 - percentArea, landArea);
    }
    else {
        cout << "Calculating profit margins for a single vegetable using 100% land area" << endl;
        calculateFarmRevenue(totalRevenue, totalCost, 100, landArea);
    }
    cout
        << fixed << showpoint << setprecision(2)
        << "=================================" << endl
        << "Total Revenue: $" << totalRevenue << endl;

    if (totalRevenue > totalCost) {
        cout << "Total Profit: $" << totalRevenue - totalCost << endl;
    }
    else {
        cout << "Total Loss: $" << totalCost - totalRevenue << endl;
    }
    return 0;
}

void calculateFarmRevenue(double &totalRevenue, double &totalCost, int percentArea, int landArea) {
    double
        correctedArea = static_cast<double>(landArea) * (static_cast<double>(percentArea) / 100.0),
        seedCost,
        plantationCost,
        fertilizingCost,
        laborCost,
        sellingPrice;

    cout << correctedArea << endl;

    cout << "Enter the seed cost per acre: ";
    cin >> seedCost;

    cout << "Enter the plantation cost per acre: ";
    cin >> plantationCost;

    cout << "Enter the fertilizing cost per acre: ";
    cin >> fertilizingCost;

    cout << "Enter the labor cost per acre: ";
    cin >> laborCost;

    cout << "Enter the selling price per acre: ";
    cin >> sellingPrice;

    totalCost +=
        (seedCost * correctedArea) +
        (plantationCost * correctedArea) +
        (fertilizingCost * correctedArea) +
        (laborCost * correctedArea);

    totalRevenue += sellingPrice * correctedArea;
}

int problemTwo() {
    int months = 0;

    double
        loanAmount,
        rateAsPercent,
        monthlyPayment,
        monthlyRate;

    cout << "Enter the loan amount: ";
    cin >> loanAmount;

    cout << "Enter the yearly interest rate (as a percent): ";
    cin >> rateAsPercent;

    cout << "Enter the monthly payment: ";
    cin >> monthlyPayment;

    monthlyRate = (rateAsPercent / 100) / 12;

    if ((loanAmount * monthlyRate) > monthlyPayment) {
        cout << "The monthly payment is too low. This load would never be paid off. Try again." << endl;
        return 0;
    }
    while (loanAmount > 0) {
        loanAmount += (loanAmount * monthlyRate);
        loanAmount -= monthlyPayment;
        months++;
    }

    cout << "The loan would be paid off after " << months << " months.";

    return 0;
}
