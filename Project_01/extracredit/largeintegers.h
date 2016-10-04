#ifndef LARGE_INTEGERS_H
#define LARGE_INTEGERS_H

#include <string>
#include <vector>
using namespace std;

class largeIntegers {
    public:
        largeIntegers(string input);
        void add(largeIntegers operand);
        void subtract(largeIntegers operand);
        void multiply(largeIntegers operand);
        void divide(largeIntegers operand);
        vector<int> value();
        void print() const;
    private:
        vector<int> num;
};

#endif
