//
//  main.cpp
//  108-StudentChallenge-FindingAPairOfElementsWithSumKInSortedArray
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

// Finding a pair of elements with sum K in a SORTED array
// Time Complexity: O(n)
void PairOfElementsSumK(struct Array arr, int sum) {
    int i = 0;
    int j = arr.size-1;
    
    while (i < j) {
        if (arr.A[i] + arr.A[j] == sum) {
            cout << arr.A[i] << " + " << arr.A[j] << " = " << sum << endl;
            // We need to find more pairs
            i++;
            j--;
        }
        else if (arr.A[i] + arr.A[j] < sum)
            i++;
        else if (arr.A[i] + arr.A[j] > sum)
            j--;
    }
    
}

int main() {
    struct Array arr = {{3,5,7,7,7,7,9,15,18,18}, 10};
    PairOfElementsSumK(arr, 14);
    return 0;
}


