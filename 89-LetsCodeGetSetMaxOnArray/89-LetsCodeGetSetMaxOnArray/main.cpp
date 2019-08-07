#include <stdio.h>

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr) {
    printf("\nElements are: ");
    for (int i = 0; i < arr.length; i++) { printf("%d ", arr.A[i]);}
    printf("\n");
}

// Appends an element at the end of the array
// We need a pointer to arr because this function will modify it
void Append(struct Array *arr, int x) {
    // Check to make sure that there is space in the array for new element
    if (arr->length < arr->size) {
        // Insert x at index 'length'. Then increment the length
        arr->A[arr->length++] = x;
    }
}

// We need a pointer to arr because this function will modify it
// Example: Array of size 5 and length 2: [7][6][][][]
// Insert is only valid in indices 0,1,2
// Insert is not valid in indices 3,4
void Insert(struct Array *arr, int index, int x) {
    // Check to make sure that the index is valid
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) { arr->A[i] = arr->A[i-1]; }
        arr->A[index] = x;
        arr->length++; // Update the length of the array
    }
}

// We need a pointer to arr because this function will modify it
// Example: Array of size 5 and length 2: [7][6][][][]
// Delete is only valid in indices 0,1
// Delete is not valid in indices 2,3,4
int Delete(struct Array *arr, int index) {
    int x = 0; // We need to return the deleted element
    // Check to make sure that the index is valid
    if (index >= 0 && index <= arr->length-1) {
        x = arr->A[index];
        for (int i = index; i < arr->length-1; i++) {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--; // Update the length of the array
        return x;
    }
    return 0; // Returns 0 if index is invalid
}

// Passing the 'arr' by value because we are only searching, not modifying.
int LinearSearch(struct Array arr, int key) {
    
    for (int i = 0; i < arr.length; i++) {
        if (key == arr.A[i]) return i;
    }
    // If 'key' not found, return -1. -1 because it is not a valid index.
    return -1;
}

// BINRAY SEARCH - ITERATIVE
// Passing the 'arr' by value because we are only searching, not modifying.
int BinarySearch(struct Array arr, int key) {
    int l,mid,h;
    l = 0;
    h = arr.length - 1;
    while (l <= h) {
        mid = (l+h)/2;
        if (key == arr.A[mid]) { return mid; }
        else if (key < arr.A[mid]) { h = mid-1;}
        else { l = mid+1;}
    }
    
    // If 'key' not found, return -1. -1 because it is not a valid index.
    return -1;
}

// BINRAY SEARCH - RECURSIVE
int RecBinarySearch(int a[], int l, int h, int key) {
    int mid;
    if (l <= h) {
        mid = (l+h)/2;
        if (key == a[mid]) { return mid; }
        else if (key < a[mid]) { return RecBinarySearch(a, l, mid-1, key); }
        else { return RecBinarySearch(a, mid+1, h, key); }
    }
    return -1;
}

// GET -- Given an index to an array, returns the element in that array
// Passing the 'arr' by value because we are NOT modifying it.
int Get(struct Array arr, int index) {
    // Check that the 'index' is valid
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1; // If invalid 'index', return -1
}

// SET -- Replaces an existing element in the array with a new element 'x'
// Passing the 'arr' by address because we are modifying it.
void Set(struct Array *arr, int index, int x) {
    // Check that the 'index' is valid
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

// MAX - Given an array (either unsorted or sorted), finds the max element
// Passing the 'arr' by value because we are NOT modifying it.
int Max(struct Array arr) {
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

// MIN - Given an array (either unsorted or sorted), finds the min element
// Passing the 'arr' by value because we are NOT modifying it.
int Min(struct Array arr) {
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

// SUM - Given an array, returns the sum of all the elements
// Passing the 'arr' by value because we are NOT modifying it.
int Sum(struct Array arr) {
    int s = 0;
    for (int i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

// AVG - Given an array, returns the average of all the elements
// Passing the 'arr' by value because we are NOT modifying it.
float Avg(struct Array arr) {
    return (float) Sum(arr)/arr.length; // Typecast the result as float
}

int main(){
    struct Array arr = {{2,3,4,5,6}, 10, 5};
    Display(arr);
    Set(&arr,1,15);
    Set(&arr,3,1);
    Display(arr);
    printf("Get: %d\n", Get(arr,2));
    printf("Max: %d\n", Max(arr));
    printf("Min: %d\n", Min(arr));
    printf("Sum: %d\n", Sum(arr));
    printf("Avg: %f\n", Avg(arr));
    return 0;
}


