//
//  main.c
//  237-LetsCodeQueueUsingArray
//
//  Created by Tenzing Rabgyal on 9/11/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for 'malloc'

struct Queue {
    int size;
    int front;
    int rear;
    int *Q; // pointer to an array in the heap
};

void create(struct Queue *q, int sz) {
    q->size = sz;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x) {
    if (q->rear == q->size-1)
        printf("Queue is full\n");
    else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;
    
    if (q->front == q->rear)
        printf("Queue is empty\n");
    else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q) {
    for (int i = q.front+1; i <= q.rear; i++)
        printf("%d ",q.Q[i]);
    printf("\n");
}

int main() {
    struct Queue q;
    create(&q, 5);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(q);
    printf("Deleted element: %d\n", dequeue(&q));
    display(q);
    printf("Deleted element: %d\n", dequeue(&q));
    display(q);
    printf("Deleted element: %d\n", dequeue(&q));
    display(q);
    printf("Deleted element: %d\n", dequeue(&q));
    display(q);
    
    return 0;
}
