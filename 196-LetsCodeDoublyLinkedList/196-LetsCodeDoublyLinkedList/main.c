//
//  main.c
//  196-LetsCodeDoublyLinkedList
//
//  Created by Tenzing Rabgyal on 8/21/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for 'malloc'

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n) {
    struct Node *t, *last;
    
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    
    for (int i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node* p) {
    while(p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int length(struct Node* p) {
    int len = 0;
    
    while(p) {
        len++;
        p = p->next;
    }
    return len;
}


int main() {
    int A[] = {10,20,30,40,50};
    create(A,5);
    
    printf("The length of the doubly LL: %d\n",length(first));
    
    display(first);

    return 0;
}
