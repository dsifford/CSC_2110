#include "money.h"

Money::Money() {
    dollars = 0;
    cents = 0;
}

Money::Money(int d, int c) {
    dollars = d;
    cents = c;
}

double Money::value() const {
    double d = dollars;
    double c = static_cast<double>(cents) / 100;
    return d + c;
}

int Money::getDollars() const { return dollars; }
int Money::getCents() const { return cents; }
void Money::setDollars(int d) { dollars = d; }
void Money::setCents(int c) { cents = c; }
