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

int main(){
    struct Array arr = {{2,3,4,5,6}, 10, 5};
    Insert(&arr, 0, 99); // arr length is now 6
    Insert(&arr, 6, 100); // arr length is now 7
    Append(&arr, 50); // arr length is now 8
    Display(arr);
    return 0;
    }

