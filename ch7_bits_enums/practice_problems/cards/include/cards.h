#ifndef CARDS_H
#define CARDS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define N_SUITS 4
#define N_PIPS 13

enum suit {heart, diamond, club, spade};
enum pip {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};

typedef enum suit suit;
typedef enum pip pip;

suit generate_suit();
pip generate_pip();
void generate_card(suit *s, pip *p);
void generate_hand(suit *suits, pip *pips, int n);
char suit_to_char(suit s);
char pip_to_char(pip p);
void print_hand(suit *suits, pip *pips, int n);

#endif