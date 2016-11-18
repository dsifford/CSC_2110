#ifndef MONEY_H
#define MONEY_H

class Money {
    public:
        int getDollars() const;
        int getCents() const;
        void setDollars(int d);
        void setCents(int c);
        double value() const;
        Money(int d, int c);
        Money();
    private:
        int dollars;
        int cents;
};

#endif