//
//  main.c
//  190-LetsCodeCircularLinkedList
//
//  Created by Tenzing Rabgyal on 8/19/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for 'malloc' and 'free'

struct Node {
    int data;
    struct Node *next;
}*head; // 'head' is a global pointer

void create(int A[], int n) {
    struct Node *t, *last;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head; // because this is a Circular LL
    
    last = head;
    
    for (int i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next; // 'last->next' is head
        last->next = t;
        last = t;
    }

}

void display(struct Node *h) {
    do {
        printf("%d ",h->data);
        h = h->next;
    }
    while (h != head);
    printf("\n");
}

// recursive version of 'display()'
void recDisplay(struct Node *h) {
    static int flag = 0;
    if (h != head || flag == 0) {
        flag = 1;
        printf("%d ",h->data);
        recDisplay(h->next);
    }
    flag = 0;
}

int main() {
    int A[] = {2,3,4,5,6};
    create(A,5);
    display(head);
    return 0;
}
