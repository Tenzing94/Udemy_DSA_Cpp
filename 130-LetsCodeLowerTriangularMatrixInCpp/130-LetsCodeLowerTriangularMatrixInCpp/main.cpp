//
//  main.cpp
//  130-LetsCodeLowerTriangularMatrixInCpp
//
//  Created by Tenzing Rabgyal on 8/12/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <iostream>
using namespace std;

class LowerTriangular {
private:
    int *A; // This will point to a 1D array in heap
    int n; // LowerTriangular Matrices are square, so only one value needed.
public:
    LowerTriangular() {
        n = 2;
        A = new int[n*(n+1)/2];
    }
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~LowerTriangular() {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void LowerTriangular::Set(int i, int j, int x) {
    if (i >= j)
        //A[i*(i-1)/2+j-1] = x; // ROW MAJOR MAPPING
        A[n*(j-1)-(j-2)*(j-1)/2+i-j] = x; // COLUMN MAJOR MAPPING
}

int LowerTriangular::Get(int i, int j) {
    if(i >= j)
        //return A[i*(i-1)/2+j-1]; // ROW MAJOR MAPPING
        return A[n*(j-1)-(j-2)*(j-1)/2+i-j]; // COLUMN MAJOR MAPPING
    else
        return 0;
}

void LowerTriangular::Display() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //if (i == j) cout << A[i*(i-1)/2+j-1] << " "; // ROW MAJOR MAPPING
            if (i == j) cout << A[n*(j-1)-(j-2)*(j-1)/2+i-j] << " "; // COLUMN MAJOR MAPPING
            else cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int d;
    cout << "Enter the dimension: ";
    cin >> d;
    LowerTriangular lm(d);
    int x;
    cout << "Enter all the elements\n";
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= d; j++) {
            cin >> x;
            lm.Set(i, j, x);
        }
    }
    cout << endl;
    
    lm.Display();
 
    return 0;
}
