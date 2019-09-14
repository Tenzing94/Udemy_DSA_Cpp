//
//  main.cpp
//  267-LetsCodeCreatingBinaryTreeInCpp
//
//  Created by Tenzing Rabgyal on 9/13/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <iostream>
#include "queue.h"
using namespace std;

class BinaryTree {
private:
    Node *root;
public:
    BinaryTree() { root = NULL; }
    void createBinaryTree();
    void preorderTraversal() { preorderTraversal(root); }
    void preorderTraversal(Node *p); // need parameter for recursion
    void inorderTraversal() { inorderTraversal(root); }
    void inorderTraversal(Node *p); // need parameter for recursion
    void postorderTraversal() { postorderTraversal(root); }
    void postorderTraversal(Node *p); // need parameter for recursion
    void levelorderTraversal() { levelorderTraversal(root); }
    void levelorderTraversal(Node *p); // need parameter for recursion
    int height() { return height(root); };
    int height(Node *root); // need parameter for recursion
};

// Creates a Binary Tree
void BinaryTree::createBinaryTree() {
    Node *p, *t;
    int x;
    Queue q(100); // create of Queue of size 100
    
    cout << "Enter root value: ";
    cin >> x;
    
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    
    while (!q.isEmpty()) {
        p = q.dequeue();
        
        cout << "Enter left child of " << p->data << " (enter -1 if no left child): ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << " (enter -1 if no right child): ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

// Print the nodes of Binary Tree in preorder
void BinaryTree::preorderTraversal(Node *p) {
    if (p) {
        cout << p->data << " ";
        preorderTraversal(p->lchild);
        preorderTraversal(p->rchild);
    }
}

// Print the nodes of Binary Tree in inorder
void BinaryTree::inorderTraversal(Node *p) {
    if (p) {
        inorderTraversal(p->lchild);
        cout << p->data << " ";
        inorderTraversal(p->rchild);
    }
}

// Print the nodes of Binary Tree in postorder
void BinaryTree::postorderTraversal(Node *p) {
    if (p) {
        postorderTraversal(p->lchild);
        postorderTraversal(p->rchild);
        cout << p->data << " ";
    }
}

void BinaryTree::levelorderTraversal(Node *root)
{
    Queue q(100);
    cout << root->data;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        root = q.dequeue();
        if(root->lchild)
        {
            cout << root->lchild->data;
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            cout << root->rchild->data;
            q.enqueue(root->rchild);
        }
    }
}

int BinaryTree::height(Node *root)
{
    int x = 0, y = 0;
    if(root == 0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if(x > y)
        return x+1;
    else
        return y+1;
}

int main() {
    BinaryTree bt;
    bt.createBinaryTree();
    
    cout << "Preorder: ";
    bt.preorderTraversal();
    cout << endl;
    cout << "Inorder: ";
    bt.inorderTraversal();
    cout << endl;
    cout << "Postorder: ";
    bt.postorderTraversal();
    cout << endl;

    return 0;
}
