//
//  main.c
//  142-LetsCodeToCreateSparseMatrix
//
//  Created by Tenzing Rabgyal on 8/12/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for 'malloc'

struct Element {
    int i;
    int j;
    int x;
};

struct Sparse {
    int m;
    int n;
    int num; // number of non-zero elements
    struct Element *ele; // pointer to the 'Element' structure
};

void Create(struct Sparse *s) {
    printf("Enter the dimensions\n");
    scanf("%d%d", &s->m, &s->n);
    printf("Number of non-zero elements: ");
    scanf("%d", &s->num);
    s->ele = (struct Element *)malloc(s->num*sizeof(struct Element));
    printf("Enter non-zero elements\n");
    for (int i = 0; i < s->num; i++) {
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
}

void Display(struct Sparse s) {
    int k = 0; //for iterating over the Element array in heap
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            if (i == s.ele[k].i && j == s.ele[k].j)
                printf("%d ", s.ele[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    struct Sparse s;
    Create(&s);
    Display(s);
    
    return 0;
}
