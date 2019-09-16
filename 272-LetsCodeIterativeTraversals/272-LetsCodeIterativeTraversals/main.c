//
//  main.c
//  272-LetsCodeIterativeTraversals
//
//  Created by Tenzing Rabgyal on 9/14/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

struct Node *root = NULL;

// Creates a Binary Tree
void createBinaryTree() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    
    createQueue(&q, 100); // create of Queue of size 100
    
    printf("Enter root value: ");
    scanf("%d", &x);
    
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    
    while (!isEmptyQueue(q)) {
        p = dequeue(&q);
        
        printf("Enter left child of %d (enter -1 if no left child): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d (enter -1 if no right child): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

// Iterative version - Print the nodes of Binary Tree in preorder
void preorderIterative(struct Node *p) {
    struct Stack stk;
    createStack(&stk, 100); // creating a stack of size 100
    
    // exit from loop when p is NULL AND stack is empty
    while (p != NULL || !isEmptyStack(stk)) {
        if (p) { // if p != NULL
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

// Iterative version - Print the nodes of Binary Tree in inorder
void inorderIterative(struct Node *p) {
    struct Stack stk;
    createStack(&stk, 100); // creating a stack of size 100
    
    // exit from loop when p is NULL AND stack is empty
    while (p != NULL || !isEmptyStack(stk)) {
        if (p) { // if p != NULL
            push(&stk, p);
            p = p->lchild;
        }
        else {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

int main() {
    
    createBinaryTree();
    printf("Preorder: ");
    preorderIterative(root);
    printf("\n");
    printf("Inorder: ");
    inorderIterative(root);
    printf("\n");
    
    return 0;
}
