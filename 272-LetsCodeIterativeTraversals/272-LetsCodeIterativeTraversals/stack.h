//
//  stack.h
//  272-LetsCodeIterativeTraversals
//
//  Created by Tenzing Rabgyal on 9/14/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#ifndef stack_h
#define stack_h

struct Stack {
    int size;
    int top;
    struct Node **S;
};

void createStack(struct Stack *st, int sz) {
    st->size = sz;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size*sizeof(struct Node *));
}

// Time Complexity: O(1)
void push(struct Stack *st, struct Node *x) {
    if (st->top == st->size - 1) // if stack is full
        printf("Stack Overflow\n");
    else {
        st->top++;
        st->S[st->top] = x;
    }
}

// Time Complexity: O(1)
struct Node *pop(struct Stack *st) {
    struct Node *x = NULL;
    
    if (st->top == -1) // if stack is empty
        printf("Stack Underflow\n");
    else
        x = st->S[st->top--];
    
    return x; // returns -1 if stack is empty
}

// Time Complexity: O(1)
int isEmptyStack(struct Stack st) {
    return st.top == -1;
}

// Time Complexity: O(1)
int isFullStack(struct Stack st) {
    return st.top == st.size - 1;
}

#endif /* stack_h */
