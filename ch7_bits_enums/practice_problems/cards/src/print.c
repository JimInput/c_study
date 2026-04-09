#include "cards.h"

char suit_to_char(suit s) {
    switch (s) {
    case heart:
        return 'H';
    case diamond:
        return 'D';
    case club:
        return 'C';
    case spade:
        return 'S';
    }
    return '\0';
}

char pip_to_char(pip p) {
    switch (p) {
    case ace:
        return 'A';
    case two:
        return '2';
    case three:
        return '3';
    case four:
        return '4';
    case five:
        return '5';
    case six:
        return '6';
    case seven:
        return '7';
    case eight:
        return '8';
    case nine:
        return '9';
    case ten:
        return 'T';
    case jack:
        return 'J';
    case queen:
        return 'Q';
    case king:
        return 'K';
    }
    return '\0';
}

void print_hand(suit *suits, pip *pips, int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("+-----+ ");
    }
    putchar('\n');

    for (i = 0; i < n; ++i) {
        printf("| %c   | ", suit_to_char(suits[i]));
    }
    putchar('\n');

    for (i = 0; i < n; ++i) {
        printf("|     | ");
    }
    putchar('\n');

    for (i = 0; i < n; ++i) {
        printf("|   %c | ", pip_to_char(pips[i]));
    }
    putchar('\n');

    for (i = 0; i < n; ++i) {
        printf("+-----+ ");
    }
    putchar('\n');
}