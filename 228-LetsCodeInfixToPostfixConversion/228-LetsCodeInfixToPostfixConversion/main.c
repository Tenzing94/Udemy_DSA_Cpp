//
//  main.c
//  228-LetsCodeInfixToPostfixConversion
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

// This function converts Infix to Postfix
// returns a pointer to a char string

char* infixToPostfix(char *infix) {
    int len = strlen(infix);
    char *postfix = (char *)malloc((len+2)*sizeof(char)); // +1 for '\0', +1 for arbitary char
    
    int i = 0, j = 0; // 'i' for indexing infix, 'j' for indexing postfix
    while(infix[i] != '\0') {
        
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if (pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    
    while(!isEmpty()) { // while the stack is not empty
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';
    
    return postfix;
}

int main() {
    
    char *infix = "a+b*c-d/e";
    
    // Line 97 may give issue when the top is NULL, so we will
    // push an arbitary character in the stack ('#' in this case)
    push('#');

    char *postfix = infixToPostfix(infix);
    
    printf("%s\n", postfix);
   
    return 0;
}

