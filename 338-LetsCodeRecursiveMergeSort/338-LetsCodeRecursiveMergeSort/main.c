//
//  main.c
//  338-LetsCodeRecursiveMergeSort
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
void recursiveMergeSort (int A[], int l, int h) {
    
    int mid;
    
    if (l < h) {
        mid = (l+h)/2;
        recursiveMergeSort(A, l, mid);
        recursiveMergeSort(A, mid+1, h);
        merge(A, l, mid, h);
    }
}

int main() {
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;
    
    recursiveMergeSort(A, 0, n-1);
    
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}
