//
//  queue.h
//  360-Lets_Code_BFS_and_DFS
//
//  Created by Tenzing Rabgyal on 12/8/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *front=NULL, *rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    
    if(t == NULL) // if heap memory is full
        printf("Queue is FUll\n");
    else {
        t->data=x;
        t->next=NULL;
        if(front == NULL)
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node* t;
    if(front == NULL)
        printf("Queue is Empty\n");
    else {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
return x;
}

int isEmpty()
{
    return front == NULL;
}

#endif /* queue_h */
