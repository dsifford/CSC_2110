#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
struct Node {
    T info;
    Node<T> *link;
};

template <class T>
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList<T> &otherList);
        void print() const;
        void destroy() const;
        virtual void insertFirst(const T &item) = 0;
        virtual void insertLast(const T &item) = 0;
    protected:
        int count;
        Node<T> *first;
        Node<T> *last;
    private:
        void copyList(const LinkedList<T> &otherList);
};

template <class T>
class UnorderedLinkedList : public LinkedList<T> {
    public:
        void insertFirst(const T &item);
        void insertLast(const T &item);
};

#endif