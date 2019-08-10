//
//  main.c
//  116-ReversingAString
//
//  Created by Tenzing Rabgyal on 8/9/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for 'malloc' and 'free'

// Method1 - Using an Aux array
char * reverseString(char *s) {
    int i, j;
    // Incrementing 'i' until it points to null char '\0' in array 's'
    for (i = 0; s[i] != '\0'; i++) {}
    char *aux = (char *)malloc((i+1)*sizeof(char));
    
    i--; // I should now point to the second last element in array 's'
    for (j = 0; i >= 0; j++, i--) {
        aux[j] = s[i];
    }
    aux[j] = '\0'; // Add the null char to the end of the array
    return aux;
}

// Method 2
void reverseString2(char *s) {
    int j;
    // Incrementing 'j' until it points to null char '\0' in array 's'
    for (j = 0; s[j] != '\0'; j++) {}
    
    j--; // I should now point to the second last element in array 's'
    
    char temp;
    for (int i = 0; i < j; i++, j--) {
        // swap
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    
    char s[] = "dog7890";
    printf("String is  : %s\n",s);
    reverseString2(s);
    printf("Reverse is : %s\n",s);
    return 0;
}
