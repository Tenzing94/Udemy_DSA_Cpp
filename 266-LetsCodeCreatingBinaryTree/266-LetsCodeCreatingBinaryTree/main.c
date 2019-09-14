//
//  main.c
//  266-LetsCodeCreatingBinaryTree
//
//  Created by Tenzing Rabgyal on 9/13/19.
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
    
    create(&q, 100); // create of Queue of size 100
    
    printf("Enter root value: ");
    scanf("%d", &x);
    
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    
    while (!isEmpty(q)) {
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

// Print the nodes of Binary Tree in preorder
void preorderTraversal(struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        preorderTraversal(p->lchild);
        preorderTraversal(p->rchild);
    }
}

// Print the nodes of Binary Tree in inorder
void inorderTraversal(struct Node *p) {
    if (p) {
        inorderTraversal(p->lchild);
        printf("%d ", p->data);
        inorderTraversal(p->rchild);
    }
}

// Print the nodes of Binary Tree in postorder
void postorderTraversal(struct Node *p) {
    if (p) {
        postorderTraversal(p->lchild);
        postorderTraversal(p->rchild);
        printf("%d ", p->data);
    }
}

int main() {
    
    createBinaryTree();
    printf("Preorder: ");
    preorderTraversal(root);
    printf("\n");
    printf("Inorder: ");
    inorderTraversal(root);
    printf("\n");
    printf("Postorder: ");
    postorderTraversal(root);
    printf("\n");
    
    return 0;
}
