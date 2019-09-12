//
//  main.c
//  221-LetsCodeParenthesisMatching
//
//  Created by Tenzing Rabgyal on 9/11/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
} *top = NULL; // 'top' points to the Node at the top of the stack

// Time Complexity: O(1)
void push(char x) {
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
char pop() {
    struct Node *temp;
    char x = -1;
    
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

// Parenthesis matching
int isBalanced(char *exp) {
    
    for (int i = 0; exp[i] != '\0'; i++) {
        
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')') {
            if (isEmpty()) // edge case where there are more ")" than "(" in the exp
                return 0;
            pop();
        }
    }
    return isEmpty() ? 1 : 0;
}

int main() {
    
    char *exp = "((a + b) * c - d))";
    
    if (isBalanced(exp))
        printf("The parenthesis in the expression is balanced.\n");
    else
        printf("NOT balanced.\n");
    return 0;
}
