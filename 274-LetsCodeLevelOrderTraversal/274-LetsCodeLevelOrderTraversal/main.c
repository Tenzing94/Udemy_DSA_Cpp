//
//  main.c
//  274-LetsCodeLevelOrderTraversal
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

void levelorder(struct Node *p) {
    struct Queue q;
    createQueue(&q, 100); // create a queue of size 100
    
    printf("%d ", p->data); // print the root
    enqueue(&q, p);
    
    while(!isEmptyQueue(q)) {
        p = dequeue(&q);
        if (p->lchild) {
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if (p->rchild) {
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}

int main() {
    
    createBinaryTree();
    printf("Levelorder: ");
    levelorder(root);
    printf("\n");
    
    return 0;
}
