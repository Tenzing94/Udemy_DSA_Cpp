//
//  main.c
//  318-LetsCodeBubbleSort
//
//  Created by Tenzing Rabgyal on 9/18/19.
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
//   Minimum time: O(n)
void bubbleSort(int A[], int n) {
    
    for (int i = 0; i < n-1; i++) {
        int flag = 0; // Variable for making bubbleSort adaptive
        for (int j = 0; j < n-1-i; j++) {
            if (A[j] > A[j+1]) {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main() {

    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10;
    
    bubbleSort(A, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}
