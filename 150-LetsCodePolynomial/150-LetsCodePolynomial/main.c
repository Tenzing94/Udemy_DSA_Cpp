//
//  main.c
//  150-LetsCodePolynomial
//
//  Created by Tenzing Rabgyal on 8/13/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    
};

struct Poly {
    int n; //size of the polynomial
    struct Term *terms;
};

void create(struct Poly *p) {
    printf("Number of terms?\n");
    scanf("%d", &p->n);
    p->terms = (struct Term*)malloc(p->n*sizeof(struct Term));
    
    printf("Enter terms\n");
    for (int i = 0; i < p->n; i++)
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
}

void display(struct Poly p) {
    for (int i = 0; i < p.n; i++)
        printf("%d*x^%d+", p.terms[i].coeff, p.terms[i].exp);
    printf("\n");
}

// You can also 'pass by value' since we are not modifying 'p1' or 'p2'
struct Poly *add(struct Poly *p1, struct Poly *p2) {
    
    struct Poly *sum = (struct Poly*)malloc(sizeof(struct Poly));
    
    // At most, the size of the polynomial will be the sum of 'p1' and 'p2' sizes
    sum->terms = (struct Term*)malloc((p1->n + p2->n)*sizeof(struct Term));
    
    int i,j,k; // 'i' for indexing 'p1', 'j' for indexing 'p2', 'k' for indexing 'sum'
    i = j = k = 0;
    
    while (i < p1->n && j < p2->n) {
        if(p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if(p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++] = p2->terms[j++];
        else { //both p1 and p2's exponents are equal
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    // Copy any remaining elements
    for(; i < p1->n; i++)
        sum->terms[k++] = p1->terms[i];
    for(; j < p2->n; j++)
        sum->terms[k++] = p2->terms[j];
    
    sum->n = k;
    return sum;
}

int main() {
    struct Poly p1,p2,*p3; // 'p3' is a pointer
    create(&p1);
    create(&p2);
    
    p3 = add(&p1, &p2);
    
    printf("\n");
    display(p1);
    printf("\n");
    display(p2);
    printf("\n");
    display(*p3);
    
    return 0;
}
