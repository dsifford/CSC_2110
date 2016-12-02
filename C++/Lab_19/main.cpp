/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 01.12.2016
 * Description: Recursive functions
 *   Part 1: Recursive function that sums an int array.
 *   Part 2: Recursive function that checks to see if
 *           a string is a palindrome
 */
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

int arraySum(int[], int, int = 0, int = 0);
bool isPalindrome(string);

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[5] = {28, 54, 2, 29, 63};
    int c[7] = {54, 23, 67, 345, 32, 87, 39};

    assert(arraySum(a, 10) == 55);
    assert(arraySum(b, 5) == 176);
    assert(arraySum(c, 7) == 647);

    assert(isPalindrome("madam"));
    assert(isPalindrome("tattarrattat"));
    assert(isPalindrome("derekkered"));

    assert(!isPalindrome("notapalindrome"));
    assert(!isPalindrome("nope"));
    assert(!isPalindrome("nada"));

    cout << "===== TESTS PASSED =====" << endl;
    return 0;
}

int arraySum(int arr[], int len, int i, int sum) {
    if (i == len)
        return sum;
    sum += arr[i++];
    return arraySum(arr, len, i, sum);
}

bool isPalindrome(string s) {
    int last = s.length() - 1;
    if (last <= 0)
        return true;
    return s[0] == s[last]
           ? isPalindrome(s.substr(1, last - 1))
           : false;
}