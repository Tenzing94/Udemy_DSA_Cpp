//
//  main.c
//  232-LetsCodeEvaluationOfPostfix
//
//  Created by Tenzing Rabgyal on 9/11/19.
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

int isEmpty() {
    return top ? 0 : 1;
}

char stackTop() {
    if(!isEmpty())
        return top->data;
    return '0';
}

// This function checks the precedence
int pre(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

// Checks if 'x' is an operand
int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0; // return false
    return 1;
}

// This function evaluates a postfix expression
// Time Complexity: O(n)
int eval(char *postfix) {
    
    int x1, x2, r;
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        
        if (isOperand(postfix[i]))
            push(postfix[i] - '0'); // To convert from char to int, we subtract by '0'
        else {
            x2 = pop();
            x1 = pop();
            
            switch(postfix[i]) {
                case '+' : r = x1+x2; break;
                case '-' : r = x1-x2; break;
                case '*' : r = x1*x2; break;
                case '/' : r = x1/x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int main() {
    
    char *postfix = "234*+82/-";
    
    printf("Result is: %d\n", eval(postfix));
    
    return 0;
}

