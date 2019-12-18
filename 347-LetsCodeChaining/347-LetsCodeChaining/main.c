//
//  main.c
//  347-LetsCodeChaining
//
//  Created by Tenzing Rabgyal on 12/3/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include "chains.h"

int hash(int key) {
    return key % 10;
}

void insert(struct Node *H[], int key) {
    int index = hash(key);
    SortedInsert(&H[index], key);
}

int main() {
    
    // array of pointers
    struct Node *HT[10]; // a hash table of size 10
    struct Node *temp;
    
    for (int i = 0; i < 10; i++) {
        HT[i] = NULL;
    }
    
    insert(HT, 12);
    insert(HT, 22);
    insert(HT, 42);
    
    temp = Search(HT[hash(22)], 22);
    
    printf("%d\n", temp->data);
    
    return 0;
}
