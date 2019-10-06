//
//  main.c
//  336-LetsCodeIterativeMergeSort
//
//  Created by Tenzing Rabgyal on 10/6/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>

void merge(int A[], int l, int mid, int h) {
    
    int i = l, j = mid+1, k = l;
    int B[100]; // aux array
    
    while (i <= mid && j <= h) {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];
    
    for (i = l; i <= h; i++)
        A[i] = B[i];
}

// Time Complexity: O(nlogn)
void iterativeMergeSort (int A[], int n) {
    
    int p, l, mid, h;
    
    for (p = 2; p <= n; p = p*2) {
        for (int i = 0; i+p-1 <= n; i = i+p) {
            l = i;
            h = i + p - 1;
            mid = (l+h)/2;
            merge(A, l, mid, h);
        }
    }

    if (p/2 < n)
        merge(A, 0, p/2 - 1, n);
}

int main() {
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;
    
    iterativeMergeSort(A, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}
