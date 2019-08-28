//
//  main.c
//  214-LetsCodeStackUsingArray
//
//  Created by Tenzing Rabgyal on 8/27/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *S;
};

void create(struct Stack *st) {
    printf("Enter the size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size*sizeof(int));
    
}

void display(struct Stack st) {
    for (int i = st.top; i >= 0; i--) {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

// Time Complexity: O(1)
void push(struct Stack *st, int x) {
    if (st->top == st->size - 1) // if stack is full
        printf("Stack Overflow\n");
    else {
        st->top++;
        st->S[st->top] = x;
    }
}

// Time Complexity: O(1)
int pop(struct Stack *st) {
    int x = -1;
    
    if (st->top == -1) // if stack is empty
        printf("Stack Underflow\n");
    else
        x = st->S[st->top--];
    
    return x; // returns -1 if stack is empty
}

// Time Complexity: O(1)
int peek(struct Stack st, int index) {
    int x = -1;
    
    if (st.top-index+1 < 0)
        printf("Invalid Index\n");
    else
        x = st.S[st.top-index+1];
    
    return x;
}

// Time Complexity: O(1)
int isEmpty(struct Stack st) {
    return st.top == -1;
}

// Time Complexity: O(1)
int isFull(struct Stack st) {
    return st.top == st.size - 1;
}

// Time Complexity: O(1)
int stackTop(struct Stack st) {
    if (!isEmpty(st))
        return st.S[st.top];
    return -1; // if stack is empty
}

int main() {
    
    struct Stack st;
    create(&st);
    
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    
    printf("Peek the second top element: %d \n", peek(st, 2));
    
    display(st);
    
    return 0;
}
