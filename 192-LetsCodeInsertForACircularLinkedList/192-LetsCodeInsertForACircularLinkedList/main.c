//
//  main.c
//  192-LetsCodeInsertForACircularLinkedList
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

int length(struct Node *p) {
    int len = 0;
    do {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

void insert(struct Node *p, int index, int x) {
    
    // if invalid index, return
    if (index < 0 || index > length(p))
        return;
    
    struct Node *t;
    
    // if we are inserting before the 'head'
    if (index == 0) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        
        // if the Circular LL is empty
        if (head == NULL) {
            head = t;
            head->next = head; // because this is a Circular LL
        }
        else {
            
            // we want 'p' to point to the Node before head
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t; // the new node 't' is now the 'head'
        }
    }
    else {
        // we want 'p' to point to the Node just before the index
        for (int i = 0; i < index-1; i++)
            p = p->next;
        
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int main() {
    int A[] = {5,10,15,20,25};
    create(A,5);
    display(head);
    
    insert(head, 2, 2000);
    display(head);
    insert(head, 0, 0);
    
    display(head);
    return 0;
}
