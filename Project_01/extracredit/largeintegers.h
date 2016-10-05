#ifndef LARGE_INTEGERS_H
#define LARGE_INTEGERS_H

#include <string>
#include <vector>
using namespace std;

class largeIntegers {
    public:
        largeIntegers(string input);
        largeIntegers* set(string integer);
        largeIntegers* add(largeIntegers operand);
        largeIntegers* subtract(largeIntegers operand);
        largeIntegers* multiply(largeIntegers operand);
        largeIntegers* inverse();
        bool greaterThan(largeIntegers operand);
        vector<int> value();
        string stringValue();
        void print();
        bool isNegative = false;
    private:
        vector<int> add(vector<int> operand);
        vector<int> subtract(vector<int> operand);
        vector<vector<int>> multiply(vector<int> larger, vector<int> smaller);
        bool greaterThan(vector<int> operand);
        void leftPad(int totalSize);
        vector<int> leftPad(vector<int> operand, int totalSize);
        vector<int> num;
        void clearLeadingZeroes();
        int _remainder = 0;
};

#endif
