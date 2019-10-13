//
//  main.c
//  344-LetsCodeShellSort
//
//  Created by Tenzing Rabgyal on 10/13/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>

void shellSort(int A[], int n) {
    int gap, i, j;
    
    for (gap = n/2; gap >= 1; gap /= 2) {
        
        for (i = gap; i < n; i++) {
            int temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp) {
                A[j+gap] = A[j];
                j = j - gap;
            }
            A[j+gap] = temp;
        }
    }
}

int main() {
    int A[] = {3,7,9,10,6,5,12,44,11,2}, n = 10;
    
    shellSort(A, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    return 0;
}
