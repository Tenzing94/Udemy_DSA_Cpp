//
//  main.c
//  112-FindingLengthOfAString
//
//  Created by Tenzing Rabgyal on 8/9/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>

// '\0' will determine the length of the string
int stringLen(char *s) {
    int i = 0;
    for (i = 0; s[i] != '\0'; i++) {} // Do nothing inside
    return i;
}

int main(int argc, const char * argv[]) {
    
    char s[] = {65,66,'c',68,69,'\0'}; // created in the stack
    // char s[] = "ABcDE"; // also created in the stack
    // char *s = "ABcDE"; // created in the heap
    
    printf("String: %s\n", s);
    printf("String length: %d\n", stringLen(s));
    
    return 0;
}
