//
//  main.cpp
//  238-LetsCodeQueueInCpp
//
//  Created by Tenzing Rabgyal on 9/11/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <iostream>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    int size;
    int *Q; // pointer to an array in the heap
public:
    Queue() { // Default constructor
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size) { // Parameterized constructor
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x) {
    if (rear == size-1)
        cout << "Queue is full\n";
    else {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue() {
    int x = -1;
    if (front == rear)
        cout << "Queue is empty\n";
    else {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display() {
    for (int i = front+1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << endl;
}

int main() {
    Queue q(5);
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    printf("Deleted element: %d\n", q.dequeue());
    q.display();
    printf("Deleted element: %d\n", q.dequeue());
    q.display();
    printf("Deleted element: %d\n", q.dequeue());
    q.display();
    printf("Deleted element: %d\n", q.dequeue());
    q.display();
    
    return 0;
}
