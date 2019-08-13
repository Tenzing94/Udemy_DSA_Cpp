//
//  main.c
//  124-LetsCodeDiagonalMatrix
//
//  Created by Tenzing Rabgyal on 8/11/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for malloc

// DIAGONAL MATRIX IN C
struct Matrix {
    int *A; // This will point to a 1D array in heap
    int n; // Diagonal Matrices are square, so only one value needed.
};

void Set(struct Matrix *m, int i, int j, int x) {
    if (i == j)
        m->A[i-1] = x;
}

int Get(struct Matrix m, int i, int j) {
    if(i == j)
        return m.A[i-1];
    else
        return 0;
}

void Display(struct Matrix m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            if (i == j) printf("%d ", m.A[i]);
            else printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    m.n = 4;
    m.A = (int *)malloc(m.n*sizeof(int));
    Set(&m,1,1,1);
    Set(&m,2,2,9);
    Set(&m,3,3,9);
    Set(&m,4,4,4);
    printf("Value from Get function: %d\n", Get(m,3,3));
    Display(m);
    free(m.A);
    return 0;
}
