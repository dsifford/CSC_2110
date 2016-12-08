/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 06.12.2016
 * Description: Create singly-linked lists and print values of nodes in reverse
 */
#include <iostream>
#include <cassert>
#include "linkedList.h"
using namespace std;

int main() {
    UnorderedLinkedList<int> list;

    list.insertFirst(22);
    list.insertLast(23);
    list.insertFirst(50);

    list.print();

    return 0;
}