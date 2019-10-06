//
//  main.c
//  323-LetsCodeInsertionSort
//
//  Created by Tenzing Rabgyal on 9/18/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>

// Time Complexity:
//   Maximum time: O(n^2)
//   Minimum time: O(n)
void insertionSort(int A[], int n) {
    
    for (int i = 1; i < n; i++) {
        int j = i-1;
        int x = A[i];
        
        while (j > -1 && A[j] > x) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main() {
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;
    
    insertionSort(A, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}
