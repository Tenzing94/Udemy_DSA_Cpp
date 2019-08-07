#include <stdio.h>
#include <stdlib.h>

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

// REVERSE (METHOD 1) - Reversing by using an Auxiliary Array
// Passing the 'arr' by address because we are modifying it.
void Reverse(struct Array *arr) {
    // Creating an Auxiliary Array 'B' in the Heap
    int *B = (int *)malloc(arr->length*sizeof(int));
    // Copy the elements of 'A' to 'B' in REVERSE order
    for (int i = arr->length-1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    // Copy the elements of 'B' to 'A' in SAME order
    for (int i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
    free(B); // To avoid memory leak
}

// SWAP function
void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// REVERSE (METHOD 2) - Reversing by swapping elements from each end of an array
// Passing the 'arr' by address because we are modifying it.
void Reverse2(struct Array *arr) {
    // Swapping stops once i >= j
    for (int i = 0, j = arr->length-1; i<j; i++, j--)
        Swap(&arr->A[i],&arr->A[j]);
}

// INSERT SORT - Given a sorted array and an element 'x'
// This function will insert 'x' to the correct position in the sorted array
// Passing the 'arr' by address because we are modifying it.
void InsertSort(struct Array *arr, int x) {
    int i = arr->length-1;
    // Check that there is free space in the array
    if (arr->length == arr->size)
        return;
    // Shift all the elements which are larger than 'x' to the right
    // Also ensure that 'i' will not go to negative
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    // Once we have exited the loop, we know that A[i] is less than or equal to 'x'
    // So we need to insert 'x' in A[i+1]
    arr->A[i+1] = x;
    arr->length++; // Increment the length of the array
}

// isSORTED - Given an array, it will check if the array is sorted
// Passing the 'arr' by value because we are NOT modifying it.
bool isSorted(struct Array arr) {
    // i stops before the last element in the list
    for (int i = 0; i < arr.length-1; i++) {
        if (arr.A[i] > arr.A[i+1])
            return false;
    }
    return true;
}

// REARRANGE - Rearranges an array (unsorted or sorted) so that
// all neg numbers are on the left and all pos numbers are on the right
// Passing the 'arr' by address because we are modifying it.
void Rearrange(struct Array *arr) {
    int i = 0, j = arr->length-1;
    
    while (i < j) {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] >= 0) j--;
        if (i < j)
            Swap(&arr->A[i], &arr->A[j]);
    }
}

int main(){
    struct Array arr = {{2,3,5,10,15}, 10, 5};
    InsertSort(&arr, 4);
    Display(arr);
    if (isSorted(arr))
        printf("Array is sorted\n");
    else
        printf("Array is NOT sorted\n");
    struct Array arr2 = {{5,7,-10,4,-3,2}, 10, 6};
    Rearrange(&arr2);
    Display(arr2);
    return 0;
}



