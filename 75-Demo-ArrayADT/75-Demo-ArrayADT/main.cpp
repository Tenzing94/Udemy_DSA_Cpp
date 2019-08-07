#include <stdio.h>
#include <stdlib.h> // for malloc

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr) {
    printf("\nElements are\n");
    for (int i = 0; i < arr.length; i++) { printf("%d ", arr.A[i]);}
}

int main(){
    
    struct Array arr;
    int n;
    printf("Enter the size of an array");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.length = 0;
    printf("Enter number of numbers");
    scanf("%d", &n);
    
    printf("Enter all Elements\n");
    for (int i = 0; i < n; i++) { scanf("%d", &arr.A[i]); }
    arr.length = n;
    
    Display(arr);
    
    return 0;
}

/*
 struct Array {
 int A[20];
 int size;
 int length;
 };
 
 void Display(struct Array arr) {
 printf("\nElements are\n");
 for (int i = 0; i < arr.length; i++) { printf("%d ", arr.A[i]);}
 }
 
 int main(){
 
 struct Array arr = {{2,3,4,5,6}, 20, 5};
 
 Display(arr);
 
 return 0;
 }
 */



