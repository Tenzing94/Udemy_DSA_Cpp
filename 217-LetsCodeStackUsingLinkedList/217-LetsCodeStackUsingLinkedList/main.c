//
//  main.c
//  217-LetsCodeStackUsingLinkedList
//
//  Created by Tenzing Rabgyal on 8/27/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL; // 'top' points to the Node at the top of the stack

// Time Complexity: O(1)
void push(int x) {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    
    if (temp == NULL) // if the heap memory is full
        printf("Stack DS is full. No space for new Node.\n");
    else {
        temp->data = x;
        temp->next = top;
        top = temp; // 'temp' node is now the 'top' node
    }
}

// Time Complexity: O(1)
int pop() {
    struct Node *temp;
    int x = -1;
    
    if(top == NULL)
        printf("Stack DS is empty.\n");
    else {
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

void display() {
    struct Node *p;
    p = top;
    
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    
    display();
    printf("Poped Node's data: %d\n", pop());
    printf("Poped Node's data: %d\n", pop());
 
    return 0;
}

