//
//  main.c
//  121-PermutationsOfAString
//
//  Created by Tenzing Rabgyal on 8/10/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>

// 'k' is the level of the tree
void Permutations(char s[], int k) { // 'char s[]' is the same as 'char *s'
    static int A[10] = {0};
    static char Res[10];
    
    if (s[k] == '\0') {
        Res[k] = '\0';
        printf("%s\n", Res);
    }
    else {
        for (int i = 0; s[i] != '\0'; i++) {
            if (A[i] == 0) {
                Res[k] = s[i];
                A[i] = 1;
                Permutations(s, k+1);
                A[i] = 0;
            }
        }
    }
    
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void Permutations2(char s[], int l, int h) {
    if (l == h)
        printf("%s\n", s);
    else {
        for (int i = l; i <= h; i++) {
            swap (&s[l],&s[i]);
            Permutations2(s, l+1, h);
            swap (&s[l],&s[i]);
        }
    }
}

int main() {
    
    char s[] = "XYZ";
    Permutations2(s, 0, 2);
    
    return 0;
}
