//
//  main.c
//  144-LetsCodeToAddSparseMatrix
//
//  Created by Tenzing Rabgyal on 8/12/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for 'malloc'

struct Element {
    int i; // row number
    int j; // column number
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

// You can call by value or call by address.
// This function will not modify 's1' and 's2'
// It will return a pointer to a Sparse Matrix called 'sum'
// We will create the 'sum' in the heap
struct Sparse* Add(struct Sparse *s1, struct Sparse *s2) {
    
    // If dimension of 's1' and 's2' are not same, return
    if (s1->m != s2->m || s1->n != s2->n)
        return 0;
    
    struct Sparse *sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    // At most, we will have 's1->num' + 's2->num' 'struct Element'.
    sum->ele = (struct Element *)malloc((s1->num+s2->num)*sizeof(struct Element));
    
    int i, j, k;
    i = j = k = 0; // 'i' for indexing 's1', 'j' for 's2', 'k' for 'sum'
    
    while (i<s1->num && j<s2->num) {
        if(s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if(s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else { // if row number of 's1' and 's2' are equal
            if(s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if(s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else { // if both row AND column number of 's1' and 's2' are equal
                sum->ele[k].i = s1->ele[i].i; // set row number
                sum->ele[k].j = s1->ele[i].j; // set col number
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x; // set x
            }
        }
    }
    // Copy any remaining Elements
    for (; i<s1->num; i++)
        sum->ele[k++] = s1->ele[i];
    for (; j<s2->num; j++)
        sum->ele[k++] = s2->ele[j];
    
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
    
    return sum;
}

int main() {
    struct Sparse s1, s2, *s3; // 's3' is a pointer
    printf("You need to enter the dimensions for two sparse matrices\n");
    Create(&s1);
    Create(&s2);
    printf("\n");
    s3 = Add(&s1, &s2);
    printf("Here is s3, which is the sum of s1 and s2\n");
    Display(*s3);
    
    return 0;
}
