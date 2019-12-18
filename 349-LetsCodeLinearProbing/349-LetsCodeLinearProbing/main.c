//
//  main.c
//  349-LetsCodeLinearProbing
//
//  Created by Tenzing Rabgyal on 12/4/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>

#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

int linearProbe(int H[], int key) {
    int index = hash(key);
    int i = 0;
    
    while (H[(index + i) % SIZE] != 0)
        i++;
    
    // once a free space is found
    return (index + i) % SIZE;
}

void insert(int H[], int key) {
    
    int index = hash(key);
    
    // check if the index is occupied
    if (H[index] != 0) {
        // find the next free space in the hash table
        index = linearProbe(H, key);
    }
    
    // place the key in the free space
    H[index] = key;
}

int search(int H[], int key) {
    
    int index = hash(key);
    int i = 0;
    
    while (H[(index + i) % SIZE] != key)
        i++;
    
    return (index + i) % SIZE;
}

int main() {
    
    int HT[SIZE] = {0}; // zero initialize the hash table
    
    insert(HT, 12);
    insert(HT, 25);
    insert(HT, 35);
    insert(HT, 26);
    
    //print the hash table
    printf("***** Hash Table *****\n");
    for (int i = 0; i < SIZE; i++) {
        printf("HT[%d] = %d\n", i, HT[i]);
    }
    printf("**********************\n\n");
    
    printf("Key 12 found at index: %d\n", search(HT, 12));
    printf("Key 25 found at index: %d\n", search(HT, 25));
    printf("Key 35 found at index: %d\n", search(HT, 35));
    printf("Key 26 found at index: %d\n", search(HT, 26));
    
    return 0;
}
