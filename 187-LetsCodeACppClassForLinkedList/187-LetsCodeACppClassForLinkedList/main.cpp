//
//  main.cpp
//  187-LetsCodeACppClassForLinkedList
//
//  Created by Tenzing Rabgyal on 8/18/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <iostream>
using namespace std;

template<class T>
class Node {
public: // everything in Node is public so that it is directly accessible
    T data;
    Node *next;
};

template<class T>
class LinkedList {
private:
    Node<T> *first;
public:
    LinkedList(){ first = NULL;} // default constructor
    LinkedList(T A[], int n);
    ~LinkedList();
    
    void Display();
    void Insert(int index, T x);
    T Delete(int index);
    int Length(); // same as 'count()' in our C program
};

// parameterized constructor
template<class T>
LinkedList<T>::LinkedList(T A[], int n) {
    Node<T> *t, *last;
    first = new Node<T>;
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (int i = 1; i < n; i++) {
        t = new Node<T>;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// destructor
template<class T>
LinkedList<T>::~LinkedList() {
    Node<T> *p = first;
    while(first) {
        first = first->next;
        delete p;
        p = first;
    }
}

// we can also pass the parameter by value since we are not modifying it
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(1)
template<class T>
void LinkedList<T>::Display() {
    Node<T> *p = first;
    // Iterate over the linked list
    while (p != NULL) { // same as 'while (p)'
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// counts the number of nodes in the linked list.
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(1)
template<class T>
int LinkedList<T>::Length() {
    Node<T> *p = first;
    int len = 0; // length is initially zero
    while (p) { // same as 'while (p != NULL)'
        len++;
        p = p->next;
    }
    return len; // return the length
}

// Time Complexity: O(n)
template<class T>
void LinkedList<T>::Insert(int index, T x) {
    // check if the index is valid
    if (index < 0 || index > Length())
        return;
    
    Node<T> *p = first;
    Node<T> *t = new Node<T>; //temp
    t->data = x;
    t->next = NULL;
    
    //Now we need to link the new node 't' in the linked list
    if (index == 0) { // if '0', insert before 'first' node
        t->next = first;
        first = t;
    }
    else {
        // move pointer 'p' to correct position
        for (int i = 0; i < index-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

// Time Complexity: O(n)
// returns the data of the deleted Node
// index start at 1
template<class T>
T LinkedList<T>::Delete(int index) {
    Node<T> *p = first, *q = NULL; // tail pointer
    int x = -1;
    
    // check if the index is valid
    if (index < 1 || index >Length())
        return -1;
    
    // if we want to delete the first node in LL
    if (index == 1) {
        first = first->next;
        x = p->data;
        delete p; // deleting the first Node
    }
    else {
        for (int i = 0; i < index-1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p; // deleting the first Node
    }
    return x;
}

int main() {
    char A[] = {'a','b','c','d','e'};
    LinkedList<char> l(A,5);
    l.Display();
    l.Insert(0, 'X'); // insert at the head of the LL
    l.Display();
    cout << "Length: " << l.Length() << endl;
    cout << "Deleted Element: " << l.Delete(1) << endl; // delete 1st Node
    cout << "Length: " << l.Length() << endl;
    
    l.Display();
    return 0;
}
