//
//  main.cpp
//  218-LetsCodeCppClassForStackUsingLinkedList
//
//  Created by Tenzing Rabgyal on 8/27/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;
public:
    Stack() {
        top = NULL;
    }
    bool isEmpty();
    bool isFull();
    void push(int x);
    int pop();
    int peek(int pos);
    int stackTop();
    void display();
};

bool Stack::isEmpty() {
    return top ? false : true;
}

// The Stack DS is full if the heap memory is full
bool Stack::isFull() {
    Node *temp = new Node;
    int r = temp ? false : true;
    delete temp;
    return r;
}

void Stack::push(int x) {
    Node *temp = new Node;
    
    if (isFull()) // if the heap memory is full
        cout << "Stack DS is full. No space for new Node.\n";
    else {
        temp->data = x;
        temp->next = top;
        top = temp; // 'temp' node is now the 'top' node
    }
}

int Stack::pop() {
    int x = -1;
    
    if(isEmpty())
        cout << "Stack DS is empty.\n";
    else {
        Node *temp = top;
        top = top->next;
        x = temp->data;
        delete temp;
    }
    return x;
}

void Stack::display() {
    Node *p = top;
    
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Stack::peek(int pos) {
    Node *p = top;
    
    for (int i = 0; p != NULL && i < pos-1; i++)
        p = p->next;
    
    if (p != NULL)
        return p->data;
    else
        return -1;
}

int Stack::stackTop() {
    if (top) // if 'top' is not NULL
        return top->data;
    return -1;
}

int main() {
    Stack stk;
    cout << "is Stack Empty? " << stk.isEmpty() << endl;
    cout << "is Stack Full? " << stk.isFull() << endl;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.display();
    cout << "Peek second top Node's data: " << stk.peek(2) << endl;
    cout << "Poped: " << stk.pop() << endl;
    cout << "Stack Top: " << stk.stackTop() << endl;
    cout << "is Stack Empty? " << stk.isEmpty() << endl;
    cout << "is Stack Full? " << stk.isFull() << endl;
    return 0;
}
