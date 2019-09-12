//
//  main.c
//  243-LetsCodeQueueUsingLinkedList
//
//  Created by Tenzing Rabgyal on 9/11/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for 'malloc'

struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    
    if (t == NULL) // check if the heap memory is full
        printf("Queue is full\n");
    else {
        t->data = x;
        t->next = NULL;
        
        if (front == NULL) // Special case where 't' is the first node
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue() {
    int x = -1;
    struct Node *t;
    
    if (front == NULL)
        printf("Queue is empty\n");
    else {
        t = front;
        front = front->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display() {
    struct Node *p = front;
    while(p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    printf("dequeued element: %d\n", dequeue());
    printf("dequeued element: %d\n", dequeue());
    printf("dequeued element: %d\n", dequeue());
    display();

    return 0;
}
