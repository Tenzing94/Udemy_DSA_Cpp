//
//  main.c
//  285-LetsCodeBinarySearchTree
//
//  Created by Tenzing Rabgyal on 9/14/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL; // root is a global Node variable

// Two scenarios when we call insert
// 1. BST is empty. If so, we make a new node 'p',
//     assign 'key' to p->data, make assign p to root, and exit the function
// 2. BST is not empty. If so:
//     first search the BST for an existing node with same data (key)
//     if we find one, exit the function becuase we cannot have duplciate vals in BST
//     else, we can insert the new node in the correct pos with the help of tail ptr

void insert(int key) {
    struct Node *t = root;
    struct Node *r; // tail pointer
    struct Node *p; // 'p' will be used for creating a new Node
    
    // if root is NULL, then this is the first node being inserted
    if (root == NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    
    while (t != NULL) {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        // else, we found a Node whose data matches the 'key'
        // so we exit the function because BST cannot have duplicate vals
        else
            return;
    }
    
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

void inorderTraversal(struct Node *p) {
    if (p) {
        inorderTraversal(p->lchild);
        printf("%d ", p->data);
        inorderTraversal(p->rchild);
    }
}

// returns a pointer to a Node whose data matches 'key'
// return NULL if no such Node exists in the BST
struct Node* search(int key) {
    struct Node *t = root;
    
    while (t != NULL) {
        if (key == t->data)
            return t; // if Node whose data matches 'key' is found
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL; // if Node whose data matches 'key' is not found
}

int main() {
    
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
    
    inorderTraversal(root);
    printf("\n");
    
    struct Node *temp1 = search(20);
    if (temp1)
        printf("Element %d is found\n", temp1->data);
    else
        printf("Element not found\n");
    
    struct Node *temp2 = search(100);
    if (temp2)
        printf("Element %d is found\n", temp2->data);
    else
        printf("Element not found\n");
  
    return 0;
}
