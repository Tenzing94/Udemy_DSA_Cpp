//
//  main.cpp
//  101-StudentChallenge-FindingSingleMissingElementInAnArray
//
//  Created by Tenzing Rabgyal on 8/8/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <iostream>
using namespace std;

struct Array {
    int *A;
    int size;
};

// Given a sorted array, Time Complexity: O(n)
// Using the difference between the element and the index
// Example : [6,7,9,10,11]
// Diff is 6 because: A[0] - 0 = 6
// Next, iterate over the array until the difference is not 6
// A[2] - 2 = 7, so we found the missing element
void FindSingleMissingElement(struct Array arr) {
    int low = arr.A[0];
    int diff = low - 0;
    for (int i = 0; i < arr.size; i++) {
        if (arr.A[i] - i != diff) {
            cout << "Missing element is: " << i + diff << endl;
            return;
        }
    }
    cout << "No Missing Element\n";
}
int main() {
    struct Array arr;
    arr.A = new int[10];
    arr.size = 10;
    
    arr.A[0] = 8;
    arr.A[1] = 10;
    arr.A[2] = 11;
    arr.A[3] = 12;
    arr.A[4] = 13;
    arr.A[5] = 14;
    arr.A[6] = 15;
    arr.A[7] = 16;
    arr.A[8] = 17;
    arr.A[9] = 18;
    FindSingleMissingElement(arr);
    delete []arr.A;
    return 0;
}
