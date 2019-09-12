//
//  main.c
//  241-LetsCodeCircularQueue
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
    q->front = q->rear = 0; //In Circular Queue, front and rear start at 0
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x) {
    if ((q->rear+1)%q->size == q->front)
        printf("Queue is full\n");
    else {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;
    
    if (q->front == q->rear)
        printf("Queue is empty\n");
    else {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q) {
    
    int i = q.front+1;
    do {
        printf("%d ", q.Q[i]);
        i = (i+1)%q.size;
    }
    while (i != (q.rear+1)%q.size);
    printf("\n");
}

int main() {
    struct Queue q;
    // Since one index needs to remain empty, we can have max 4 elements
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    display(q);
    printf("Deleted element: %d\n", dequeue(&q));
    display(q);
    
    return 0;
}
