//
//  main.c
//  129-LetsCodeLowerTriangularMatrixInC
//
//  Created by Tenzing Rabgyal on 8/11/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// LOWER TRIANGULAR MATRIX IN C
struct Matrix {
    int *A; // This will point to a 1D array in heap
    int n; // Lower Triangluar Matrix is a square, so only one value needed.
};

void Set(struct Matrix *m, int i, int j, int x) {
    if (i >= j)
        //m->A[i*(i-1)/2+j-1] = x; // For ROW MAJOR MAPPING
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = x; // For COLUMN MAJOR MAPPING
}

int Get(struct Matrix m, int i, int j) {
    if (i >= j)
        //return m.A[i*(i-1)/2+j-1]; // For ROW MAJOR MAPPING
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]; // For COLUMN MAJOR MAPPING
    return 0;
}

void Display(struct Matrix m) {
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            if (i >= j)
                //printf("%d ", m.A[i*(i-1)/2+j-1]); // For ROW MAJOR MAPPING
                printf("%d ", m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]); // For COLUMN MAJOR MAPPING
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    int x;
    
    printf("Please enter the dimension: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n*(m.n+1)/2*sizeof(int)); // (n(n+1))/2 size needed
    
    printf("Enter all elements\n");
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            scanf("%d", &x);
            Set(&m,i,j,x);
        }
    }
    printf("\n");
    Display(m);
    free(m.A);
    
    return 0;
}
