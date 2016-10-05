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


/**
 * Constructor method
 *   Takes a string of int as input, iterates it, and sets it to num
 */
largeIntegers::largeIntegers(string input) {
    set(input);
}

/**
 * Setter function to set the value of "num"
 * @param  input A string able to resolve to a valid integer (can be prefixed with `-`)
 * @return       Pointer to class instance to allow method chaining
 */
largeIntegers* largeIntegers::set(string input) {
    int x;
    num.clear();
    isNegative = false;
    for (int i = 0; i < input.length(); i++) {
        x = static_cast<int>(input[i]);
        if (i == 0 && x == 45) {
            isNegative = true;
            continue;
        }
        if (x < 48 || 57 < x) {
            cout << "Input string must contain only integers. Exiting..." << endl;
            exit(EXIT_FAILURE);
        }
        num.push_back(x - 48);
    }
    return this;
}

/**
 * Takes a `largeIntegers` as input and adds the value of it to the calling class.
 * @param  operand Input operand
 * @return         Pointer to class instance to allow method chaining
 */
largeIntegers* largeIntegers::add(largeIntegers operand) {
    if ((isNegative && operand.isNegative) || (!isNegative && !operand.isNegative)) {
        num = add(operand.value());
        return this;
    }
    num = subtract(operand.value());
    return this;
}

/**
 * Takes a `largeIntegers` as input and subtracts the value of it from the calling class.
 * @param  operand Input operand
 * @return         Pointer to class instance to allow method chaining
 */
largeIntegers* largeIntegers::subtract(largeIntegers operand) {
    if ((isNegative && operand.isNegative) || (!isNegative && !operand.isNegative)) {
        num = subtract(operand.value());
        return this;
    }
    num = add(operand.value());
    return this;
}

/**
 * Takes a `largeIntegers` as input and multiplys the value of it to the calling class
 * @param  operand Input operand
 * @return         Pointer to class instance to allow method chaining
 */
largeIntegers* largeIntegers::multiply(largeIntegers operand) {
    vector<int> op = operand.value();
    vector<vector<int>> products;

    if ((!isNegative && operand.isNegative) || (isNegative && operand.isNegative))
        isNegative = !isNegative;

    if (greaterThan(operand)) {
        products = multiply(num, operand.value());
    }
    else {
        products = multiply(operand.value(), num);
    }

    for (int i = 0; i < products.size(); i++) {
        if (i == 0) {
            num = products[i];
            continue;
        }
        num = add(products[i]);
    }

    return this;
}

largeIntegers* largeIntegers::inverse() {
    isNegative = !isNegative;
    return this;
}

/**
 * Returns a string representation of the value of `num`
 * @return integer string
 */
string largeIntegers::stringValue() {
    clearLeadingZeroes();
    string payload = isNegative ? "-" : "";
    for (auto x : num) {
        payload += to_string(x);
    }
    return payload;
}

/**
 * Returns the value num (pass by value)
 */
vector<int> largeIntegers::value() {
    return num;
}

/**
 * Prints the value of num to the console. If negative, a `-` is prepended
 */
void largeIntegers::print() {
    clearLeadingZeroes();
    if (isNegative) cout << "-";
    for (auto i : num)
        cout << i;
    cout << endl;
}

vector<int> largeIntegers::add(vector<int> operand) {
    _remainder = 0;
    vector<int> sum;
    auto it = sum.begin();
    int x;
    if (greaterThan(operand)) {
        sum.reserve(num.size() + 1);
        it = sum.begin();
        operand = leftPad(operand, num.size());
        for (int i = num.size() - 1; i >= 0; i--) {
            x = _remainder + operand[i] + num[i];
            _remainder = 0;
            while (x > 9) {
                _remainder++;
                x -= 10;
            }
            it = sum.insert(it, x);
            if (i == 0 && _remainder > 0)
                it = sum.insert(it, _remainder);
        }
    }
    else {
        sum.reserve(operand.size() + 1);
        it = sum.begin();
        leftPad(operand.size());
        for (int i = operand.size() - 1; i >= 0; i--) {
            x = _remainder + operand[i] + num[i];
            _remainder = 0;
            while (x > 9) {
                _remainder++;
                x -= 10;
            }
            it = sum.insert(it, x);
            if (i == 0 && _remainder > 0)
                it = sum.insert(it, _remainder);
        }
    }
    _remainder = 0;
    return sum;
}

vector<int> largeIntegers::subtract(vector<int> operand) {
    vector<int> diff;
    diff.reserve(100);
    auto it = diff.begin();
    int x;
    if (greaterThan(operand)) {
        operand = leftPad(operand, num.size());
        for (int i = num.size() - 1; i >= 0; i--) {
            if (num[i] < operand[i]) {
                num[i] += 10;
                num[i-1]--;
            }
            x = num[i] - operand[i];
            it = diff.insert(it, x);
        }
    }
    else {
        leftPad(operand.size());
        for (int i = operand.size() - 1; i >= 0; i--) {
            if (operand[i] < num[i]) {
                operand[i] += 10;
                operand[i-1]--;
            }
            x = operand[i] - num[i];
            it = diff.insert(it, x);
        }
        isNegative = !isNegative;
    }
    return diff;
}

vector<vector<int>> largeIntegers::multiply(vector<int> larger, vector<int> smaller) {
    const int LARGER = larger.size() - 1;
    const int SMALLER = smaller.size() - 1;
    vector<vector<int>> collection;
    vector<int> product;
    collection.reserve(smaller.size());
    auto it = collection.begin();
    auto innerIt = product.begin();
    int x, i, j;

    for (i = SMALLER; i >= 0; i--) {
        _remainder = 0;
        product.clear();
        product.reserve(smaller.size() + (SMALLER - i));
        product.assign(SMALLER - i, 0);
        innerIt = product.begin();
        for (j = LARGER; j >= 0; j--) {
            x = smaller[i] * larger[j] + _remainder;
            _remainder = x / 10;
            x -= _remainder * 10;
            innerIt = product.insert(innerIt, x);
            if (j == 0 && _remainder > 0)
                innerIt = product.insert(innerIt, _remainder);
        }
        it = collection.insert(it, product);
    }
    return collection;
}

void largeIntegers::clearLeadingZeroes() {
    if (num[0] != 0) return;
    auto it = num.begin();
    while (num[0] == 0 && num.size() > 1) {
        it = num.erase(it);
    }
    if (num[0] == 0) isNegative = false;
}

vector<int> largeIntegers::leftPad(vector<int> operand, int totalSize) {
    operand.reserve(totalSize);
    auto it = operand.begin();
    while (operand.size() < totalSize) {
        operand.insert(it, 0);
    }
    return operand;
}

void largeIntegers::leftPad(int totalSize) {
    auto it = num.begin();
    while (num.size() < totalSize) {
        num.insert(it, 0);
    }
}

bool largeIntegers::greaterThan(largeIntegers operand) {
    if (num.size() > operand.value().size())
        return true;
    if (num.size() < operand.value().size())
        return false;
    return num > operand.value();
}
bool largeIntegers::greaterThan(vector<int> operand) {
    if (num.size() > operand.size())
        return true;
    if (num.size() < operand.size())
        return false;
    return num > operand;
}
