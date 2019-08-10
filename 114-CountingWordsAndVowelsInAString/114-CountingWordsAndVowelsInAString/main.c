//
//  main.c
//  114-CountingWordsAndVowelsInAString
//
//  Created by Tenzing Rabgyal on 8/9/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>

int countVowels(char *s) {
    int countV = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
            || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            countV++;
        }
    }
    return countV;
}

int countConsonants(char *s) {
    int countAlpha = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        // First make sure that it is an alphabet
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            countAlpha++;
        }
    }
    return countAlpha - countVowels(s);
}

// Example: "Car goes fast"
//      * has 2 spaces, so there are 3 words
// Example: "Car goes  fast"
//      * has 3 spaces, two infront of 'fast'.
//      * to ensure that we only count 2 spaces, we need to make
//        sure that we count whitespaces of size > 1 as just 1 space
int countWords(char *s) {
    int countW = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        // s[i-1] condition to make sure we count whitespaces as just 1 space
        if(s[i] == ' ' && s[i-1] != ' ') {
            countW++;
        }
    }
    return ++countW;
}

int main() {
    
    char s[] = "How Are       You";
    
    printf("String: %s\n", s);
    printf("Number of vowels: %d\n", countVowels(s));
    printf("Number of consonants: %d\n", countConsonants(s));
    printf("Number of words: %d\n", countWords(s));
    
    return 0;
}
