//
//  main.c
//  294-Lets_Code_LL_Rotation_on_AVL
//
//  Created by Tenzing Rabgyal on 9/15/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    int height; // for 'balance factor'
    struct Node *rchild;
} *root = NULL;

// In this code, the height starts from 1 onwards

// This function compares the node's left child's height
// with node's right child's height
// It will return the larger of the two heights
int nodeHeight(struct Node *p) {
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    
    return hl>hr ? hl+1 : hr+1;
}

int balanceFactor(struct Node *p) {
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    
    return hl-hr;
}

struct Node* LLrotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    
    pl->rchild = p;
    p->lchild = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    
    // If the node we are rotating is root, update it
    if (p == root)
        root = pl;
    
    return pl;
}

struct Node* LRrotation(struct Node *p) {
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    
    plr->lchild = pl;
    plr->rchild = p;
    
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    plr->height = nodeHeight(plr);
    
    // If the node we are rotating is root, update it
    if (root == p)
        root = plr;
    
    return plr;
}

// Not implemented
struct Node* RRrotation(struct Node *p) {
    return NULL;
}

// Not implemented
struct Node* RLrotation(struct Node *p) {
    return NULL;
}

// Recursive insert
struct Node* recursiveInsert(struct Node *p, int key) {
    
    if (p == NULL) {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1; // height of 1 because 't' is the only node currently in BST
        t->lchild = t->rchild = NULL;
        return t;
    }
    
    if (key < p->data) {
        p->lchild = recursiveInsert(p->lchild, key);
    }
    else if (key > p->data) {
        p->rchild = recursiveInsert(p->rchild, key);
    }
    
    p->height = nodeHeight(p);
    
    // If so, perform LL Rotation
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LLrotation(p);
    // If so, perform LR Rotation
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LRrotation(p);
    // If so, perform RR Rotation
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RRrotation(p);
    // If so, perform RL Rotation
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RLrotation(p);
    
    return p;
}

int main() {
    
    root = recursiveInsert(root, 10);
    root = recursiveInsert(root, 5);
    root = recursiveInsert(root, 2);
    
    printf("The root Node is: %d\n", root->data);
    
    return 0;
}
