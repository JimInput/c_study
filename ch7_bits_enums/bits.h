#ifndef BITS_H
#define BITS_H

#include <stdio.h>
#include <limits.h>

void bit_print(int a);

int pack(char a, char b, char c, char d);

char unpack(int p, int k); // k = 0..3 (for the 4 bytes)



#endif