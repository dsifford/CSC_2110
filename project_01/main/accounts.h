#ifndef ACCOUNTS_H
#define ACCOUNTS_H

class bankAccount {
    public:
        bankAccount(int num = 0, double bal = 0);
        void setAcctNumber(int num);
        int getAcctNumber() const;
        double getBalance() const;
        void deposit(double money);
        void withdraw(double money);
        void printInfo() const;
    protected:
        int acctNumber;
        double balance;
};

class checkingAccount: public bankAccount {
    public:
        checkingAccount(int acctNumber = 0, double bal = 0, double interest = 0, double minBal = 0);
        void setInterestRate(double interest);
        double getInterestRate() const;
        void setMinBalance(double minBal);
        double getMinBalance() const;
        double getServiceCharges() const;
        void postInterest();
        bool balanceBelowMinimum() const;
        void writeCheck(double amount);
        void withdraw(double amount);
        void printInfo() const;
    private:
        const double SERVICE_CHARGE = 10.00;
        double interestRate;
        double minBalance;
        double serviceCharges = 0;
        void applyServiceCharge();
};

class savingsAccount: public bankAccount {
    public:
        savingsAccount(int acctNumber = 0, double bal = 0, double interest = 0);
        void setInterestRate(double interest);
        double getInterestRate() const;
        void postInterest();
        void withdraw(double amount);
        void printInfo() const;
    private:
        double interestRate;
        double accruedInterest = 0;
};

#endif
