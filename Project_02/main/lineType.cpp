#include <iostream>
#include <cmath>
#include "lineType.h"
using namespace std;

ostream &operator<<(ostream &os, const LineType &line) {
    os << line.a << "x + " << line.b << "y = " << line.c;
    return os;
}

istream &operator>> (istream &is, LineType &line) {
    is >> line.a >> line.b >> line.c;
    return is;
}

const LineType &LineType::operator=(const LineType &rhs) {
    if (this == &rhs) return *this;
    this->a = rhs.a;
    this->b = rhs.b;
    this->c = rhs.c;
    return *this;
}

bool LineType::operator+() const {
    return b == 0;
}

bool LineType::operator-() const {
    return a == 0;
}

bool LineType::operator==(const LineType &line) const {
    return this->a == line.a && this->b == line.b && this->c == line.c;
}

bool LineType::operator||(const LineType &line) const {
    return (this->slope() == line.slope()) || (this->b == 0 && line.b == 0);
}

bool LineType::operator&&(const LineType &line) const {
    if ((this->a == 0 && line.b == 0) || (this->b == 0 && line.a == 0))
        return true;
    return (this->slope() * line.slope()) == -1;
}

LineType::LineType(double A, double B, double C) {
    if (A == 0 && B == 0) exit(EXIT_FAILURE);
    this->a = A;
    this->b = B;
    this->c = C;
}

double LineType::slope() const {
    return b == 0 ? NAN : -a / b;
}

point LineType::intersection(const LineType &line) const {
    point intersect = {
        .x = NAN,
        .y = NAN,
    };

    if (*this || line) {
        return intersect;
    }
    double RHS[2][1] = {
        {c},
        {line.c}
    };
    double determinant = 1 / ((a * line.b) - (b * line.a));
    double identity[2][2] = {
        {line.b *determinant, (-1 * b) * determinant},
        {(-1 * line.a) * determinant, a * determinant},
    };
    intersect.x = (identity[0][0] * RHS[0][0]) + (identity[0][1] * RHS[1][0]);
    intersect.y = (identity[1][0] * RHS[0][0]) + (identity[1][1] * RHS[1][0]);

    return intersect;
}