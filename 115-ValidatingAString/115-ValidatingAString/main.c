//
//  main.c
//  115-ValidatingAString
//
//  Created by Tenzing Rabgyal on 8/9/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>

// A string is valid if it consists of alphabets and numbers only
// Side Note: Apparently, 'bool' type does not exist in C
int validateString(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (!(s[i] >= 'a' && s[i] <= 'z') &&
            !(s[i] >= 'A' && s[i] <= 'Z') &&
            !(s[i] >= '0' && s[i] <= '9'))
              return 0;
    }
    return 1;
}

int main() {
    
    char s[] = "T?nzing1ab";
    
    printf("%s\n", s);
    if (validateString(s))
        printf("String is valid\n");
    else
        printf("String is NOT valid\n");
    
    s[1] = 'e'; // Replacing '?' with 'e'
    
    printf("%s\n", s);
    if (validateString(s))
        printf("String is valid\n");
    else
        printf("String is NOT valid\n");
        
    return 0;
}
