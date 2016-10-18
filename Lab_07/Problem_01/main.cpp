/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 18.10.2016
 * Description: Program to find the "last largest index" of an int array
 */
#include <iostream>
#include <cassert>
using namespace std;

int lastLargestIndex(const int arr[], int size);
void runTests();

int main() {
    runTests();
    return 0;
}

int lastLargestIndex(const int arr[], int size) {
    int index = 0;
    int largest = arr[0];

    for (size_t i = 1; i < size; i++) {
        if (arr[i] >= largest) {
            index = i;
            largest = arr[i];
        }
    }
    return index;
}

void runTests() {
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    assert(lastLargestIndex(arr1, 10) == 9);

    int arr2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    assert(lastLargestIndex(arr2, 10) == 0);

    int arr3[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    assert(lastLargestIndex(arr3, 10) == 9);

    int arr4[10] = {1, 1, 400, 1, 1, 1, 400, 1, 1, 1};
    assert(lastLargestIndex(arr4, 10) == 6);
    cout << "==== Tests Passed ====" << endl;
}
