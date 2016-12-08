#include <iostream>
#include "linkedList.h"
using namespace std;

template <class T>
LinkedList<T>::LinkedList() {
    first = NULL;
    last = NULL;
    count = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    this->destroyList();
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    first = NULL;
    copyList(list);
}

template <class T>
void LinkedList<T>::copyList(const LinkedList<T> &list) {
    Node<T> *newNode;
    Node<T> *current;

    if (first != NULL)
        destroy();
    if (list.first == NULL) {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else {
        current = list.first;
        count = list.count;
        first = new Node<T>;
        first->link = NULL;
        last = first;
        current = current->link;

        while (current != NULL) {
            newNode = new Node<T>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template <class T>
void LinkedList<T>::destroy() const {
    Node<T> *temp;
    while (first != NULL) {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = NULL;
    count = 0;
}

template <class T>
void LinkedList<T>::print() const {
    Node<T> *current = first;
    while (current->link != NULL) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

template <class T>
void UnorderedLinkedList<T>::insertFirst(const T &item) {
    Node<T> node = new Node<T>;
    node->info = item;
    node->link = this->first;
    this->first = node;
    this->count++;
    if (this->last == NULL)
        this->last = node;
}

template <class T>
void UnorderedLinkedList<T>::insertLast(const T &item) {
    Node<T> node = new Node<T>;
    node->info = item;
    node->link = NULL;
    this->last->link = node;
    this->count++;
    if (this->first == NULL)
        this->first = node;
}