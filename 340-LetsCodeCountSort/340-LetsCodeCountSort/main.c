//
//  main.c
//  340-LetsCodeCountSort
//
//  Created by Tenzing Rabgyal on 10/13/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int findMaxElement(int A[], int n) {
    int max = INT32_MIN;
    for (int i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}
void countSort(int A[], int n) {
    
    int i, j;
    int max = findMaxElement(A, n);
    int *C = (int *)malloc(sizeof(int)*(max+1));
    
    // zero initialize C array
    for (i = 0; i < max+1; i++) {
        C[i] = 0;
    }
    
    for (i = 0; i < n; i++) {
        C[A[i]]++;
    }
    
    i = 0;
    j = 0;
    
    while(j < max+1) {
        if (C[j] > 0) {
            A[i++] = j;
            C[j]--;
        }
        else {
            j++;
        }
    }
}

int main() {
    int A[] = {3,7,9,10,6,5,12,44,11,2}, n = 10;
    
    countSort(A, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}
