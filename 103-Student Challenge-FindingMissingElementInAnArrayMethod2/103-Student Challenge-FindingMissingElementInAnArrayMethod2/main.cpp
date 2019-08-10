//
//  main.cpp
//  103-Student Challenge-FindingMissingElementInAnArrayMethod2
//
//  Created by Tenzing Rabgyal on 8/8/19.
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





// Works for both sorted and unsorted arrays. Time Complexity: O(n)
// NOTE: This code could be better written using a hash table
void FindMultipleMissingElements(struct Array arr) {
    int max = Max(arr);
    int min = Min(arr);
    // Create a temp array of size max element of 'arr'
    // Since arrays are zero indexed, we need size max+1
    int *tempArr = new int[max+1](); // zero initialized
    
    for (int i = 0; i < arr.size; i++)
        tempArr[arr.A[i]] = 1;
    
    cout << "Missing Elements: ";
    for (int i = min; i <= max; i++) {
        if (tempArr[i] == 0)
            cout << i << " ";
    }
    cout << endl;
    delete []tempArr;
}

int main() {
    struct Array arr = {{5,6,4,8,10,2,7,15,13,18}, 10};
    
    FindMultipleMissingElements(arr);
    return 0;
}


