//
//  main.c
//  333-LetsCodeQuickSort
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

int partition(int A[], int l, int h) {
    int pivot = A[l]; // first element will be pivot
    int i = l, j = h;
    
    do {
        do {i++;} while (A[i] <= pivot);
        do {j--;} while (A[j] > pivot);
        
        if (i < j)
            swap(&A[i], &A[j]);
    } while(i < j);
    
    swap(&A[l], &A[j]); // swap pivot element with A[j]
    
    return j;
}

// Time Complexity:
//      Best Case: O(nlogn)
//      Worst Case: O(n^2)
void quickSort(int A[], int l, int h) {
    int j;
    if (l < h) {
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j+1, h);
    }
}

int main() {
    int A[] = {3,7,9,10,6,5,12,4,11,2,INT32_MAX}, n = 11; //INT32_MAX will act as infinity
    
    quickSort(A, 0, n-1);
    
    for (int i = 0; i < n-1; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}
