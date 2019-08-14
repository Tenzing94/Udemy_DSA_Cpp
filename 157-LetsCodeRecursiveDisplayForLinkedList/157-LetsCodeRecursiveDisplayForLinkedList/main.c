//
//  main.c
//  157-LetsCodeRecursiveDisplayForLinkedList
//
//  Created by Tenzing Rabgyal on 8/14/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for 'malloc'

struct Node {
    int data;
    struct Node *next;
}*first = NULL; // this is a global pointer

void create(int A[], int n) {
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (int i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// we can also pass the parameter by value since we are not modifying it
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(1)
void display(struct Node *p) {
    
    // Iterate over the linked list
    while (p != NULL) { // same as 'while (p)'
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// recursive version of 'display function'
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(n)
void recDisplay(struct Node *p) {
    if (p != NULL) { // same as 'if (p)'
        printf("%d ", p->data);
        recDisplay(p->next);
    }
}

// displays the linked list data in reverse order
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(n)
void revRecDisplay(struct Node *p) {
    if (p != NULL) { // same as 'if (p)'
        revRecDisplay(p->next);
        printf("%d ", p->data);
    }
}

int main() {
    int A[] = {3,5,7,10,15};
    create(A,5);
    recDisplay(first);
    printf("\n");
    revRecDisplay(first);
    printf("\n");
    return 0;
}
