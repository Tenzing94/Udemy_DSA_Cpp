//
//  main.c
//  278-LetsCodeHeightAndCount
//
//  Created by Tenzing Rabgyal on 9/14/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
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

int count (struct Node *p) {
    int x, y;
    if (p) {
        x = count(p->lchild);
        y = count(p->rchild);
        return x + y + 1; // counting
    }
    return 0;
}

int height (struct Node *p) {
    int x = 0, y = 0;
    if (p == NULL)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    
    if (x > y)
        return x+1;
    else
        return y+1;
}

int main() {
    
    createBinaryTree();
    printf("\n");
    printf("Count : %d\n", count(root));
    printf("Height: %d\n", height(root));
    
    return 0;
}
