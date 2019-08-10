//
//  main.c
//  113-ChangingCaseOfAString
//
//  Created by Tenzing Rabgyal on 8/9/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>

// ASCII CODES:
// A == 65      a == 97       Diff = 32
// B == 66      b == 98       Diff = 32
// .            .
// .            .
// Z == 90      z == 122      Diff = 32
// Difference between upper case and lower case letters is 32

void UpperCase(char *s) {
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
    }
}

void ToggleCase(char *s) {
    for (int i = 0; s[i] != '\0'; i++)
    {
        // Any non-Alphabetical symbol will remain untouched
        if (s[i] >= 97 && s[i] <= 'z')
            s[i] -= 32;
        else if (s[i] >= 'A' && s[i] <= 90)
            s[i] += 32;
    }
}

int main(int argc, const char * argv[]) {
    
    char s1[] = "Mo Money 5% & Mo Problems";
    char s2[] = "ABcDE7";
    
    UpperCase(s1);
    printf("Upper Case: %s\n", s1);
    
    ToggleCase(s2);
    printf("Toggle Case: %s\n", s2);
  
    return 0;
}

