//
//  main.c
//  119-FindingDuplicatesInAStringUsingBitwiseOperations
//
//  Created by Tenzing Rabgyal on 8/9/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>

// this function only works for lower case alphabets
void duplicates (char *s) {
    
    // We need 26 bits, but we can get it only in bytes, so we get 32 bits
    // Similar idea to the "hashing" using array
    uint32_t H = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        uint32_t x = 1;
        
        x = x << (s[i] - 97); // Moving x to the appropriate place
        
        // Mask so that we can check
        if (H & x) // if H AND x is greater than 0.
            printf("%c is a duplicate\n",s[i]);
        // Else, Merge
        else
            H = H | x;
    }
}

int main() {

    char s[] = "ttennzinngg";
    duplicates(s);
    
    return 0;
}
