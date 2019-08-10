//
//  main.cpp
//  106-StudentChallenge-FindingDuplicatesInAUnsortedArray
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

// MAX - Given an array (either unsorted or sorted), finds the max element
int Max(struct Array arr) {
    int max = arr.A[0];
    for (int i = 1; i < arr.size; i++) {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

// MIN - Given an array (either unsorted or sorted), finds the min element
int Min(struct Array arr) {
    int min = arr.A[0];
    for (int i = 1; i < arr.size; i++) {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

// We are using a simple form of hashing, which is an array
// Time Complexity: O(n)
void FindDupInArrayUsingHashing(struct Array arr) {
    int min = Min(arr);
    int max = Max(arr);
    int *tempArr = new int[max+1](); // zero initialized
    
    for (int i = 0; i < arr.size; i++) {
        tempArr[arr.A[i]]++;
    }
    
    for (int i = min; i < max+1; i++) {
        if (tempArr[i] > 1)
            cout << "Element " << i << " has " << tempArr[i] << " duplicates\n";
    }
    
    delete []tempArr;
}

int main() {
    struct Array arr = {{8,6,5,25,8,4,8,25,5,8}, 10};
    
    FindDupInArrayUsingHashing(arr);
    return 0;
}


