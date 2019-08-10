//
//  main.cpp
//  104-StudentChallenge-FindingDuplicatesInASortedArray
//
//  Created by Tenzing Rabgyal on 8/9/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <iostream>
using namespace std;

struct Array {
    int A[10];
    int size;
};

// Find the duplicate values in a sorted array
void FindDupInSortedArray(struct Array arr) {
    int lastDuplicate = 0;
    for (int i = 0; i < arr.size-1; i++) {
        if (arr.A[i] == arr.A[i+1] && arr.A[i] != lastDuplicate) {
            cout << arr.A[i] << " ";
            lastDuplicate = arr.A[i];
        }
    }
    cout << endl;
}

// Find the duplicate values in a sorted array
// and count the number of duplicates
// Time Complexity: O(n)
void FindDupAndCountInSortedArray(struct Array arr) {
    for (int i = 0, j = 0; i < arr.size-1; i++) {
        if (arr.A[i] == arr.A[i+1]) {
            j = i+1;
            while (arr.A[j] == arr.A[i])
                j++;
            cout << "Element " << arr.A[i] << " appears " << j - i << " times\n";
            i = j - 1;
        }
    }
}

int main() {
    struct Array arr = {{3,5,7,7,7,7,9,15,18,18}, 10};
    cout << "Function 1: Find duplicates\n";
    FindDupInSortedArray(arr);
    cout << "Function 2: Find and count the duplicates\n";
    FindDupAndCountInSortedArray(arr);
    
    return 0;
}




