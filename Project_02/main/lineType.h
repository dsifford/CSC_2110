#ifndef LINE_TYPE_H
#define LINE_TYPE_H

#include <iostream>
using namespace std;

struct point {
    double x;
    double y;
};

class LineType {
    public:
        friend ostream &operator<<(ostream &, const LineType &);
        // Overloads stream insertion operator to pretty print the line to stdout
        // Postcondition: print to stdout in the form of "ax + by = c"
        friend istream &operator>>(istream &, LineType &);
        // Overloads the stream extraction operator for easy input.
        // Postcondition: stream read to a, then b, then c.
        const LineType &operator=(const LineType &);
        // Overloads the assignment operator to copy another line to this
        // Postcondition: values of the other line are copied to this
        bool operator+() const;
        // Postcondition: returns true if line is vertical (b == 0)
        bool operator-() const;
        // Postcondition: returns true if line is horizontal (a == 0)
        bool operator==(const LineType &) const;
        // Postcondition: returns true if a, b, and c are equal in both lines
        bool operator||(const LineType &) const;
        // Postcondition: returns true if lines are parallel (same slope or are either
        //    both vertical or both horizontal)
        bool operator&&(const LineType &) const;
        // Postcondition: returns true if lines are perpendicular (one horizontal
        //    + one vertical OR products of slopes == -1)
        double slope() const;
        // If line is not vertical, return the slope, else return NaN
        // Postcondition: Slope or NaN returned
        point intersection(const LineType &) const;
        // If this and comparing line are not parallel, return intersection point
        // Postcondition: point type returned containing either valid type double
        //   for both x and y or NaN for both x and y
        LineType(double A, double B, double C);
        // Constructor:
        // Sets a, b, and c to A, B, and C, respectively.
        // Exits with EXIT_FAILURE if A and B are both 0
    private:
        double a;
        double b;
        double c;
};

#endif
