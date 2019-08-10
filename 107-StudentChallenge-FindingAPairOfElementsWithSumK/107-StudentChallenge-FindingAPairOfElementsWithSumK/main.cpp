//
//  main.cpp
//  107-StudentChallenge-FindingAPairOfElementsWithSumK
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
void x(struct Array arr, int sum) {
    int max = Max(arr);
    int *tempArr = new int[max+1](); // zero initialized
    
    for (int i = 0; i < arr.size; i++) {
        if ((tempArr[sum-arr.A[i]] > 0) && (sum-arr.A[i] > 0)) {
            cout << arr.A[i] << " + " << sum - arr.A[i] << " = " << sum << endl;
            return;
        }
        tempArr[arr.A[i]]++;
    }
    
    
    delete []tempArr;
}

int main() {
    struct Array arr = {{8,6,5,25,8,4,8,25,5,8}, 10};
    
    x(arr, 10);
    return 0;
}
