/**
 * Program Name: largeintegers.cpp
 * Developer: Derek P Sifford
 * Date: 02.10.2016
 * Description: largeIntegers class file
 */
#include "largeintegers.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

largeIntegers::largeIntegers(string input) {
    int x;
    for (int i = 0; i < input.length(); i++) {
        x = static_cast<int>(input[i]);
        if (x < 48 || 57 < x) {
            cout << "Input string must contain only integers. Exiting..." << endl;
            exit(EXIT_FAILURE);
        }
        num.push_back(x - 48);
    }
}

void largeIntegers::add(largeIntegers operand) {
    vector<int> sum;
    auto it = sum.begin();
    int _remainder = 0;
    int x;
    if (operand.value() > num) {
        for (int i = operand.value().size() - 1; i >= 0; i--) {
            if (!num[i]) {
                x = _remainder;
            }
            else {
                x = _remainder + num[i];
            }
            _remainder = 0;
            x += operand.value()[i];
            while (x > 9) {
                _remainder++;
                x -= 10;
            }
            it = sum.insert(it, x);
        }
    }
    else {
        for (int i = num.size() - 1; i >= 0; i--) {
            if (!operand.value()[i]) {
                x = _remainder;
            }
            else {
                x = _remainder + operand.value()[i];
            }
            _remainder = 0;
            x += num[i];
            while (x > 9) {
                _remainder++;
                x -= 10;
            }
            it = sum.insert(it, x);
        }
    }
    num = sum;
}

vector<int> largeIntegers::value() {
    return num;
}

void largeIntegers::print() const {
    for (auto i : num)
        cout << i;
    cout << endl;
}
