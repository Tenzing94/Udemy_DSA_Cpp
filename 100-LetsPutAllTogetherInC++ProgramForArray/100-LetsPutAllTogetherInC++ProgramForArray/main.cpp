#include <iostream>
using namespace std;

template<class T>
class Array {
private:
    T *A;
    int size;
    int length;
public:
    Array() { // Default Constructor
        size = 10;
        A = new T[10];
        length = 0;
    }
    Array(int sz) { // Parameterized Constructor
        size = sz;
        A = new T[sz];
        length = 0;
    }
    ~Array() { // Destructor
        delete []A;
    }
    void Display();
    void Insert(int index, T x);
    T Delete(int index);
};

template<class T>
void Array<T>::Display() {
    cout << "\nElements are: ";
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

template<class T>
void Array<T>::Insert(int index, T x) {
    // Check to make sure that the index is valid
    if (index >= 0 && index <= length) {
        for (int i = length; i > index; i--) { A[i] = A[i-1]; }
        A[index] = x;
        length++; // Update the length of the array
    }
}

template<class T>
T Array<T>::Delete(int index) {
    int x = 0; // We need to return the deleted element
    // Check to make sure that the index is valid
    if (index >= 0 && index <= length-1) {
        x = A[index];
        for (int i = index; i < length-1; i++)
            A[i] = A[i+1];
        length--; // Update the length of the array
        return x;
    }
    return 0; // Returns 0 if index is invalid
}


int main() {
    Array<char> arr(10);
    
    arr.Insert(0,'a');
    arr.Insert(1, 'c');
    arr.Insert(2, 'd');
    arr.Display();
    cout << arr.Delete(0);
    arr.Display();
    return 0;
}

