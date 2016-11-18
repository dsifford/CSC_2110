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

    if (_greaterThan(operand)) {
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

/**
 * Takes a `largeIntegers` as input, inverts the sign, and returns a pointer to itself
 * @return Pointer to class instance to allow method chaining
 */
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

/**
 * Private method used internally to add the value of the input param to `num`
 * @param vector<int> operand The value to add to `num`
 * @return vector<int> The value of `num` + input param
 */
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
        num = leftPad(num, operand.size());
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

/**
 * Private method used internally to subtract the value of the input param from `num`
 * @param vector<int> operand The value to subtract from `num`
 * @return vector<int> The value of `num` - input param
 */
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
        num = leftPad(num, operand.size());
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

/**
 * Private method used internally to multiply two integer vectors
 * @param vector<int> larger The larger input vector (unsigned)
 * @param vector<int> smaller The smaller input vector (unsigned)
 * @return vector<vector<int>> A vector of vectors representing the products of each
 *     position of the input vectors (final product requires the addition of each
 *     element in the vector)
 */
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

/**
 * Private method used to clear all leading zeroes from num
 */
void largeIntegers::clearLeadingZeroes() {
    if (num[0] != 0) return;
    auto it = num.begin();
    while (num[0] == 0 && num.size() > 1) {
        it = num.erase(it);
    }
    if (num[0] == 0) isNegative = false;
}

/**
 * Private method used to add leading zeroes to an integer vector
 * @param vector<int> operand Vector to perform operation on
 * @param int totalSize The total size the output vector should be after adding
 *   the leading zeroes
 * @return vector<int> Vector of integers with leading zeroes added
 */
vector<int> largeIntegers::leftPad(vector<int> operand, int totalSize) {
    operand.reserve(totalSize);
    auto it = operand.begin();
    while (operand.size() < totalSize) {
        operand.insert(it, 0);
    }
    return operand;
}

/**
 * Public method used to compare two largeIntegers (both size and sign)
 * @param largeIntegers operand The comparing largeIntegers
 * @return bool The truth value for this > operand
 */
bool largeIntegers::greaterThan(largeIntegers operand) {
    if (num.size() > operand.value().size()) {
        if (isNegative)
            return false;
        return true;
    }
    if (num.size() < operand.value().size()) {
        if (operand.isNegative)
            return true;
        return false;
    }
    if (num > operand.value()) {
        if (isNegative)
            return false;
        return true;
    }
    if (num < operand.value()) {
        if (operand.isNegative)
            return true;
        return false;
    }
    if ((isNegative && operand.isNegative) || (!isNegative && !operand.isNegative))
        return false;
    if (isNegative && !operand.isNegative)
        return false;
    return true;
}

/**
 * Private method used internally to perform an unsigned comparison between this
 *   and another `largeIntegers`
 * @param largeIntegers operand Comparator
 * @return bool Truth value for this > operand (unsigned)
 */
bool largeIntegers::_greaterThan(largeIntegers operand) {
    if (num.size() > operand.value().size())
        return true;
    if (num.size() < operand.value().size())
        return false;
    return num > operand.value();
}

/**
 * Private method used internally to perform an unsigned comparison between `num`
 *   and another integer vector
 * @param vector<int> operand Comparator
 * @return bool Truth value for this > operand (unsigned)
 */
bool largeIntegers::greaterThan(vector<int> operand) {
    if (num.size() > operand.size())
        return true;
    if (num.size() < operand.size())
        return false;
    return num > operand;
}
