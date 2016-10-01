#include "accounts.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bankAccount::bankAccount(int num, double bal) {
    balance = bal;
    acctNumber = num;
}
void bankAccount::setAcctNumber(int num) {
    acctNumber = num;
}
int bankAccount::getAcctNumber() const {
    return acctNumber;
}
double bankAccount::getBalance() const {
    return balance;
}
void bankAccount::deposit(double money) {
    balance += money;
}
void bankAccount::withdraw(double money) {
    balance -= money;
}
void bankAccount::printInfo() const {
    cout
        << fixed << setprecision(2)
        << "=== Account Info ===" << endl
        << "\tAccount Number: " << acctNumber << endl
        << "\tBalance: $" << balance << endl;
}


checkingAccount::checkingAccount(int acctNumber, double bal, double interest, double minBal): bankAccount(acctNumber, bal) {
    interestRate = interest;
    minBalance = minBal;
}
void checkingAccount::setInterestRate(double interest) {
    if (interest > 1) {
        interestRate = interest / 100;
        return;
    }
    interestRate = interest;
}
double checkingAccount::getInterestRate() const {
    return interestRate;
}
void checkingAccount::setMinBalance(double minBal) {
    minBalance = minBal;
}
double checkingAccount::getMinBalance() const {
    return minBalance;
}
double checkingAccount::getServiceCharges() const {
    return serviceCharges;
}
void checkingAccount::postInterest() {
    double interest = balance * interestRate;
    balance += interest;
}
bool checkingAccount::balanceBelowMinimum() const {
    return balance < minBalance;
}
void checkingAccount::writeCheck(double amount) {
    balance -= amount;
    if (balance < minBalance) {
        cout << "Your balance has fallen below the minimum balance" << endl;
        applyServiceCharge();
    }
}
void checkingAccount::withdraw(double amount) {
    balance -= amount;
    if (balance < minBalance) {
        cout << "Your balance has fallen below the minimum balance" << endl;
        applyServiceCharge();
    }
}
void checkingAccount::printInfo() const {
    bankAccount::printInfo();
    cout
        << "\tInterest Rate: " << interestRate << endl
        << "\tMinimum Balance: $" << minBalance << endl
        << "\tService Charges: $" << serviceCharges << endl;
}
void checkingAccount::applyServiceCharge() {
    serviceCharges += SERVICE_CHARGE;
    balance -= SERVICE_CHARGE;
}


savingsAccount::savingsAccount(int acctNumber, double bal, double interest): bankAccount(acctNumber, bal) {
    interestRate = interest;
}
void savingsAccount::setInterestRate(double interest) {
    if (interest > 1) {
        interestRate = interest / 100;
        return;
    }
    interestRate = interest;
}
double savingsAccount::getInterestRate() const {
    return interestRate;
}
void savingsAccount::postInterest() {
    double interest = balance * interestRate;
    balance += interest;
    accruedInterest += interest;
}
void savingsAccount::withdraw(double amount) {
    balance -= amount;
}
void savingsAccount::printInfo() const {
    bankAccount::printInfo();
    cout
        << "\tInterest Rate: " << interestRate << endl
        << "\tAccrued Interest: $" << accruedInterest << endl;
}
