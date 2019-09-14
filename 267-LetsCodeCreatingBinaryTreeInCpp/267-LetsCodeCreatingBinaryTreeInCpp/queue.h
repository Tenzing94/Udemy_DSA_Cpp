//
//  queue.h
//  267-LetsCodeCreatingBinaryTreeInCpp
//
//  Created by Tenzing Rabgyal on 9/13/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#ifndef queue_h
#define queue_h

class Node {
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue {
private:
    int front;
    int rear;
    int size;
    Node **Q; // pointer to an array in the heap
public:
    Queue() { // Default constructor
        front = rear = 0;
        size = 10;
        Q = new Node*[size];
    }
    Queue(int size) { // Parameterized constructor
        front = rear = 0;
        this->size = size;
        Q = new Node*[this->size];
    }
    void enqueue(Node *x);
    Node* dequeue();
    bool isEmpty();
};

void Queue::enqueue(Node *x) {
    if ((rear+1)%size == front)
        std::cout << "Queue is full\n";
    else {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

Node* Queue::dequeue() {
    Node* x = NULL;
    
    if (front == rear)
        std::cout << "Queue is empty\n";
    else {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

bool Queue::isEmpty() {
    return front == rear;
}

#endif /* queue_h */
