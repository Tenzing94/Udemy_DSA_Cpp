//
//  main.c
//  328-LetsCodeSelectionSort
//
//  Created by Tenzing Rabgyal on 10/6/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Time Complexity:
//   Maximum time: O(n^2)
//   Minimum time: O(n^2)
// Selection Sort is NOT adaptive
// Selection Sort is NOT stable
void selectionSort(int A[], int n) {
    
    for (int i = 0; i < n-1; i++) {
        int j = i;
        int k = i;
        
        for (; j < n; j++) {
            if (A[j] < A[k]) {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

int main() {
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;
    
    selectionSort(A, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}
