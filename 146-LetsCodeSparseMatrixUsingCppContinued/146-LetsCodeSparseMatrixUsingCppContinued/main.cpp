//
//  main.cpp
//  146-LetsCodeSparseMatrixUsingCppContinued
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
    // we can overload '+' operator using member function or friend function
    // we will do member function for overloading '+' operator
    Sparse operator + (Sparse &s);
    
    // we will do friend function for overloading '>>' and '<<' operator
    friend istream & operator >> (istream &is, Sparse &s); // replacing 'read()' with this
    friend ostream & operator << (ostream &os, Sparse &s); // replacing 'display()' with this
};

Sparse Sparse::operator + (Sparse &s) {
    
    // If dimension of 'this' and 's' are not same, return
    if (this->m != s.m || this->n != s.n)
        return Sparse(0,0,0);
    
    Sparse *sum = new Sparse(this->m, this->n, this->num + s.num);
    
    int i,j,k; // 'i' for indexing 'this', 'j' for 's', 'k' for 'sum'
    i = j = k = 0;
    
    while (i < this->num && j < s.num) {
        if (this->ele[i].i < s.ele[j].i)
            sum->ele[k++] = this->ele[i++];
        else if (this->ele[i].i > s.ele[j].i)
            sum->ele[k++] = s.ele[j++];
        else { // if row number of 'this' and 's' are equal
            if (this->ele[i].j < s.ele[j].j)
                sum->ele[k++] = this->ele[i++];
            else if (this->ele[i].j > s.ele[j].j)
                sum->ele[k++] = s.ele[j++];
            else { // if both row AND column number of 'this' and 's' are equal
                sum->ele[k].i = this->ele[i].i;
                sum->ele[k].j = this->ele[i].j;
                sum->ele[k++].x = this->ele[i++].x + s.ele[j++].x;
            }
        }
    }
    // Copy any remaining elements
    for (; i < this->num; i++)
        sum->ele[k++] = this->ele[i];
    for (; j < s.num; j++)
        sum->ele[k++] = s.ele[j];
    
    sum->m = this->m;
    sum->n = this->n;
    sum->num = k;
    
    return *sum; // dereference, then return
}

//no need for scope resolution as this is a 'friend function' of Sparse class
istream & operator >> (istream &is, Sparse &s) {
    cout << "Enter non-zero elements\n";
    for (int i = 0; i < s.num; i++)
        cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    return is;
}

//no need for scope resolution as this is a 'friend function' of Sparse class
ostream & operator << (ostream &os, Sparse &s) {
    int k = 0; //for iterating over the Element array in heap
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            if (s.ele[k].i == i && s.ele[k].j == j)
                cout << s.ele[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return os;
}

int main() {
    Sparse s1(5,5,5);
    Sparse s2(5,5,5);
    cin >> s1;
    cin >> s2;
    Sparse sum = s1+s2;
    
    cout << "First Matrix" << endl << s1;
    cout << "Second Matrix" << endl << s2;
    cout << "Sum Matrix" << endl << sum;
    return 0;
}
