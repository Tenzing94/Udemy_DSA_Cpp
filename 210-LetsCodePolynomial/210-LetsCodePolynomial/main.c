//
//  main.c
//  210-LetsCodePolynomial
//
//  Created by Tenzing Rabgyal on 8/27/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // for 'pow' function

struct Node {
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;

void create() {
    
    struct Node *temp = NULL, *last = NULL;
    int num;
    
    printf("Enter number of terms: ");
    scanf("%d",&num);
    printf("Enter each term with coeff and exp\n");
    
    for (int i = 0; i < num; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &temp->coeff, &temp->exp);
        temp->next = NULL;
        
        // If first node
        if (poly == NULL) {
            poly = last = temp;
        }
        else {
            last->next = temp;
            last = temp;
        }
    }
}

void display(struct Node *p) {
    while(p) {
        printf("%dx^%d + ", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

long eval(struct Node *p, int x) {
    long val = 0;
    
    while(p) {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

int main() {

    create();
    display(poly);
    printf("If x is 2, the eval function returns: %ld\n",eval(poly, 2));
    
    return 0;
}
