//
//  main.cpp
//  145-LetsCodeSparseMatrixUsingCpp
//
//  Created by Tenzing Rabgyal on 8/13/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <iostream>
using namespace std;

class Element {
public:
    // public so that they are directly accessible
    int i; // row number
    int j; // column number
    int x;
};

class Sparse {
private:
    int m; // Dimension of Sparse - number of rows
    int n; // Dimension of Sparse - number of cols
    int num; // number of non-zero elements
    Element *ele; // pointer to 'Element' object/s
public:
    // We will not write a default constructor
    Sparse(int m, int n, int num) {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }
    ~Sparse() {
        delete [] ele;
    }
    void read() {
        cout << "Enter non-zero elements\n";
        for (int i = 0; i < num; i++)
            cin >> ele[i].i >> ele[i].j >> ele[i].x;
    }
    void display() {
        int k = 0; //for iterating over the Element array in heap
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ele[k].i == i && ele[k].j == j)
                    cout << ele[k++].x << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main() {
    Sparse s1(5,5,5);
    s1.read();
    s1.display();
    return 0;
}
