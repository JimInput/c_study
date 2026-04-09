// Write a program that counts the total number of letters.
// Use redirection to test your program.
// nletters < infile > outfile (just console here)

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int count = 0;
    char x;
    while (scanf("%c", &x) == 1) {
        if (isalpha(x))
            ++count;
    }

    printf("Number of letters: %d\n", count);
    return 0;
}