#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ispalindrome(char* s);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("\n%s%s%s\n\n%s\n%s\n\n",
            "Usage:  ", argv[0], "  string",
            "Returns TRUE if the given string is a palindrome.",
            "Returns FALSE otherwise.");
            exit(1);
    }
    printf("%s\n", ispalindrome(argv[1]) ? "TRUE" : "FALSE");
    return 0;
}

int ispalindrome(char* s) {
    int n = strlen(s);
    int i;
    for (i = 0; i < n/2; i++) {
        if (s[i] != s[n-i-1])
            return 0;
    }
    return 1;
}