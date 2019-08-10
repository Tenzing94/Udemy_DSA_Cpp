//
//  main.cpp
//  102-StudentChallenge-FindingMultipleMissingElementsInAnArray
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

// The input 'arr' needs to be a SORTED array. Time Complexity is O(n), while loop is negligible
// Using the difference between the element and the index
// Example : [6,7,9,10,13,14]
// Diff: A[0] - 0 is 6
// Iterate until the Diff is not 6. A[2] - 2 is 7, so go to while loop.
// Inside while loop, print out 'i + diff', which is 8 (aka the missing value).
// Then increment the diff value. Diff is now 7. In the next iteration, the while loop condition fails.
// Iterate until the Diff is not 7. A[4] - 4 is 9, so go to while loop.
// Inside while loop, print out 'i + diff', which is 11 (aka the missing value).
// Then increment the diff value. Diff is now 8. While loop condition fails, so go to next iteration.
// Inside while loop, print out 'i + diff', which is 12 (aka the missing value).
// Then increment the diff value. Diff is now 9. In the next iteration, the while loop condition fails.
// And so on...
void FindMultipleMissingElements(struct Array arr) {
    int diff = arr.A[0] - 0;
    for (int i = 0; i < arr.size; i++) {
        if (arr.A[i] - i != diff) {
            while (diff < arr.A[i] - i) {
                cout << i + diff << endl;
                diff++;
            }
        }
    }
}
int main() {
    struct Array arr = {{3,4,5,6,7,9,10,13,14,15}, 10};
    
    // arr.A = {8,10,11,12,13,14,15,16,17,18};
    // This initializer list is illegal syntax for arrays inside a struct.
    // Makes sense because initializer list can only be used during initialzation
    // Either assign the values when you create the struct object, like how I did it above
    // Or assign it individually like this: arr.A[6] = 29;
    
    FindMultipleMissingElements(arr);
    return 0;
}





