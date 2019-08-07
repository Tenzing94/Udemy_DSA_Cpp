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

int main(){
    struct Array arr = {{2,3,4,5,6}, 10, 5};
    Insert(&arr, 0, 99); // arr length is now 6
    Insert(&arr, 6, 100); // arr length is now 7
    Append(&arr, 50); // arr length is now 8
    Display(arr);
    printf("Deleted element: %d\n", Delete(&arr,6));
    Display(arr);
    return 0;
}

