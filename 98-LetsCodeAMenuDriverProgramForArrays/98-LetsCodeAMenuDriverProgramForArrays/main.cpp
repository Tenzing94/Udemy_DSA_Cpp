#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
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

// MERGE - Merges two SORTED arrays
struct Array* Merge(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    // Once we reach this point, we know we have finished with one of the arrays
    // So all we have to do is copy the other array's elements to the end of 'arr3'
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}









// UNION Set operation for SORTED sets
// Merge set A and set B such that all of the elements in the new set is unique
struct Array* Union(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        // If A[i] == A[j], we only copy one of them to arr3
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    // Once we reach this point, we know we have finished with one of the arrays
    // So all we have to do is copy the other array's elements to the end of 'arr3'
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

// INTERSECTION Set operation for SORTED sets
// Find the elements which are common on both sets and copy them to a new set
struct Array* Intersection(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr1->A[i] > arr2->A[j])
            j++;
        // If A[i] == A[j], we only copy one of them to arr3
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

// DIFFERENCE Set operation for SORTED sets
// Find all the elements of set A which are not present in set B
struct Array* Difference(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else {
            i++;
            j++;
        }
    }
    // Once we reach this point, we know we have finished with one of the arrays
    // If we were done with arr1, then we are done
    // If we were done with arr2, then we need to copy the remaining arr1 elements to arr3
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main(){
    struct Array arr1;
    int ch, x, index;
    
    printf("Enter the Size of Array: ");
    scanf("%d", &arr1.size);
    // In struct Array, A is now a pointer. In previous videos, it was an array: A[10]
    arr1.A = (int *)malloc(arr1.size*sizeof(int));
    arr1.length = 0;
    
    do {
        printf("MENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: printf("Enter an element and index: ");
                scanf("%d%d", &x, &index);
                Insert(&arr1, index, x);
                break;
            case 2: printf("Enter index: ");
                scanf("%d", &index);
                x = Delete(&arr1, index);
                printf("Deleted element is %d\n", x);
                break;
            case 3: printf("Enter element to search: ");
                scanf("%d", &x);
                index = LinearSearch(arr1, x);
                printf("Element index is %d\n", index);
                break;
            case 4: printf("Sum is %d\n", Sum(arr1));
                break;
            case 5: Display(arr1);
                break;
            
        }
    } while(ch < 6);
    
    free(arr1.A);
    return 0;
}


