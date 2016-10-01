/**
 * Program Name: project_01
 * Developer: Derek P Sifford
 * Date: 01.10.2016
 * Description: Bank account program
 */
#include <iostream>
#include "./accounts.h"
#include <cassert>
#include <cmath>
using namespace std;

// class bankAccount {
//     public:
//         bankAccount(int num = 0, double bal = 0) {
//             balance = bal;
//             acctNumber = num;
//         }
//         void setAcctNumber(int num) {
//             acctNumber = num;
//         }
//         int getAcctNumber() const {
//             return acctNumber;
//         }
//         double getBalance() const {
//             return balance;
//         }
//         void deposit(double money) {
//             balance += money;
//         }
//         void withdraw(double money) {
//             balance -= money;
//         }
//         void printInfo() const {
//             cout
//                 // << fixed << setprecision(2)
//                 << "=== Account Info ===" << endl
//                 << "\tAccount Number: " << acctNumber << endl
//                 << "\tBalance: $" << balance << endl;
//         }
//     protected:
//         int acctNumber;
//         double balance;
// };
//
// class checkingAccount: public bankAccount {
//     public:
//         checkingAccount(int acctNumber = 0, double bal = 0, double interest = 0, double minBal = 0): bankAccount(acctNumber, bal) {
//             interestRate = interest;
//             minBalance = minBal;
//         }
//         void setInterestRate(double interest) {
//             if (interest > 1) {
//                 interestRate = interest / 100;
//                 return;
//             }
//             interestRate = interest;
//         }
//         double getInterestRate() const {
//             return interestRate;
//         }
//         void setMinBalance(double minBal) {
//             minBalance = minBal;
//         }
//         double getMinBalance() const {
//             return minBalance;
//         }
//         double getServiceCharges() const {
//             return serviceCharges;
//         }
//         void postInterest() {
//             double interest = balance * interestRate;
//             balance += interest;
//         }
//         bool balanceBelowMinimum() const {
//             return balance < minBalance;
//         }
//         void writeCheck(double amount) {
//             balance -= amount;
//             if (balance < minBalance) {
//                 cout << "Your balance has fallen below the minimum balance" << endl;
//                 applyServiceCharge();
//             }
//         }
//         void withdraw(double amount) {
//             balance -= amount;
//             if (balance < minBalance) {
//                 cout << "Your balance has fallen below the minimum balance" << endl;
//                 applyServiceCharge();
//             }
//         }
//         void printInfo() const {
//             bankAccount::printInfo();
//             cout
//                 << "\tInterest Rate: " << interestRate << endl
//                 << "\tMinimum Balance: $" << minBalance << endl
//                 << "\tService Charges: $" << serviceCharges << endl;
//         }
//     private:
//         const double SERVICE_CHARGE = 10.00;
//         double interestRate;
//         double minBalance;
//         double serviceCharges = 0;
//         void applyServiceCharge() {
//             serviceCharges += SERVICE_CHARGE;
//             balance -= SERVICE_CHARGE;
//         }
// };
//
// class savingsAccount: public bankAccount {
//     public:
//         savingsAccount(int acctNumber = 0, double bal = 0, double interest = 0): bankAccount(acctNumber, bal) {
//             interestRate = interest;
//         }
//         void setInterestRate(double interest) {
//             if (interest > 1) {
//                 interestRate = interest / 100;
//                 return;
//             }
//             interestRate = interest;
//         }
//         double getInterestRate() const {
//             return interestRate;
//         }
//         void postInterest() {
//             double interest = balance * interestRate;
//             balance += interest;
//             accruedInterest += interest;
//         }
//         void withdraw(double amount) {
//             balance -= amount;
//         }
//         void printInfo() const {
//             bankAccount::printInfo();
//             cout
//                 << "\tInterest Rate: " << interestRate << endl
//                 << "\tAccrued Interest: $" << accruedInterest << endl;
//         }
//     private:
//         double interestRate;
//         double accruedInterest = 0;
// };


int main() {

    /**
     * Base class tests
     */
    bankAccount account;
    assert(account.getAcctNumber() == 0);
    assert(account.getBalance() == 0.0);

    account.setAcctNumber(12);
    account.deposit(14.50);
    assert(account.getAcctNumber() == 12);
    assert(account.getBalance() == 14.5);

    account.deposit(3.25);
    assert(account.getBalance() == 17.75);

    account.withdraw(7.75);
    assert(account.getBalance() == 10.0);

    account.printInfo();

    /**
     * Checking account tests
     */
    checkingAccount account1;
    assert(account1.getAcctNumber() == 0);
    assert(account1.getBalance() == 0.0);
    assert(account1.getInterestRate() == 0);
    assert(account1.getMinBalance() == 0);
    assert(account1.getServiceCharges() == 0);
    assert(account1.balanceBelowMinimum() == 0);

    account1.setAcctNumber(45);
    account1.setInterestRate(4.25);
    account1.setMinBalance(10);
    assert(account1.getAcctNumber() == 45);
    assert(account1.getInterestRate() == 0.0425);
    assert(account1.getMinBalance() == 10.0);
    assert(account1.balanceBelowMinimum() == 1);

    account1.deposit(50);
    assert(account1.getBalance() == 50.0);

    account1.writeCheck(5.50);
    assert(account1.getBalance() == 44.5);
    assert(account1.balanceBelowMinimum() == 0);

    account1.withdraw(4.5);
    assert(account1.getBalance() == 40.0);
    assert(account1.balanceBelowMinimum() == 0);

    account1.withdraw(50);
    assert(account1.getBalance() == -20.0);
    assert(account1.balanceBelowMinimum() == 1);
    assert(account1.getServiceCharges() == 10.0);

    account1.writeCheck(10);
    assert(account1.getBalance() == -40.0);
    assert(account1.balanceBelowMinimum() == 1);
    assert(account1.getServiceCharges() == 20.0);

    account1.deposit(50);
    account1.postInterest();
    assert(account1.getBalance() == 10.425);
    assert(account1.balanceBelowMinimum() == 0);

    account1.printInfo();

    /**
     * Savings account tests
     */
    savingsAccount account2(77);

    assert(account2.getAcctNumber() == 77);
    assert(account2.getBalance() == 0.0);
    assert(account2.getInterestRate() == 0);

    account2.setInterestRate(3.25);
    assert(account2.getInterestRate() == 0.0325);

    account2.deposit(45.50);
    account2.postInterest();
    assert(round(account2.getBalance() * 100) == 4698);

    account2.setInterestRate(0.05);
    account2.postInterest();
    assert(account2.getInterestRate() == 0.05);
    assert(round(account2.getBalance() * 100) == 4933);

    account2.withdraw(10);
    assert(round(account2.getBalance() * 100) == 3933);

    account2.printInfo();

    cout << "==== Tests Passed ===" << endl;
    return 0;
}
