//
//  main.c
//  287-LetsCodeRecursiveInsertAndDeleteOnBST
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

// Recursive insert
struct Node* recursiveInsert(struct Node *p, int key) {
    
    if (p == NULL) {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    
    if (key < p->data) {
        p->lchild = recursiveInsert(p->lchild, key);
    }
    else if (key > p->data) {
        p->rchild = recursiveInsert(p->rchild, key);
    }
    return p;
}

int height (struct Node *p) {
    if (p == NULL)
        return 0;
    
    int x = height(p->lchild);
    int y = height(p->rchild);
    return x>y ? x+1 : y+1;
}

struct Node* inorderPredecessor(struct Node *p) {
    while (p && p->rchild != NULL)
        p = p->rchild;
    
    return p;
}

struct Node* inorderSuccessor(struct Node *p) {
    while (p && p->lchild != NULL)
        p = p->lchild;
    
    return p;
}

struct Node* delete(struct Node *p, int key) {
    
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL) { // if 'p' is a leaf node
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    
    if (key < p->data)
        p->lchild = delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = delete(p->rchild, key);
    
    // else, a Node whose 'data' matches the 'key' is found, so delete it
    // we need to replace the Node with either its inorder predecessor or inorder successor
    //      we will decide based on the height of left subtree and right subtree
    //      if the height of left subtree is more, we will make replace with the predecessor
    //      else if the height of right subtree is more, we will make replace with the successor
    //      else, we can delete from any side
    else {
        if (height(p->lchild) > height(p->rchild)) {
            struct Node * q = inorderPredecessor(p->lchild);
            p->data = q->data; // replacing the data
            p->lchild = delete(p->lchild, q->data);
        }
        else {
            struct Node* q = inorderSuccessor(p->rchild);
            p->data = q->data; // replacing the data
            p->rchild = delete(p->rchild, q->data);
        }
    }
    return p;
}

int main() {
    
    root = recursiveInsert(root, 10);
    recursiveInsert(root, 5);
    recursiveInsert(root, 20);
    recursiveInsert(root, 8);
    recursiveInsert(root, 30);
    
    inorderTraversal(root);
    printf("\n");
    
    delete(root, 20);
    
    inorderTraversal(root);
    printf("\n");
    
    struct Node *temp1 = search(20);
    if (temp1)
        printf("Element %d is found\n", temp1->data);
    else
        printf("Element not found\n");
    
    struct Node *temp2 = search(30);
    if (temp2)
        printf("Element %d is found\n", temp2->data);
    else
        printf("Element not found\n");
    
    return 0;
}
