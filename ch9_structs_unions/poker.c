#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define DEBUG

#ifdef DEBUG
    #define DEBUG_ONLY(...) __VA_ARGS__;
#else
    #define DEBUG_ONLY(...) 
#endif

#define NDEALS 10000
#define NPLAYERS 6
#define NCARDS 52
#define NHAND 5

typedef enum{clubs, diamonds, hearts, spades} cdhs;

typedef struct card {
    int pips : 4;
    cdhs suit : 2;
} card;

card assign_values(int pips, cdhs suit);
void construct_deck(card deck[NCARDS]);
void prn_card_values(card *c_ptr);
void play_poker(card deck[NCARDS]);
void shuffle(card deck[NCARDS]);
void swap(card *p, card *q);
void deal_the_cards(card deck[NCARDS], card hand[NPLAYERS][NHAND]);
int is_flush(card h[NHAND]);

int main(void) {
    card deck[NCARDS];

    printf("%ld\n", sizeof(card));
    construct_deck(deck);
    
    DEBUG_ONLY(
    for (i = 0; i < NCARDS; ++i)
        prn_card_values(&deck[i]);
    )
    // play_poker(deck);
    return 0;
}

card assign_values(int pips, cdhs suit) {
    card c;
    c.pips = pips;
    c.suit = suit;
    return c;
}

void construct_deck(card deck[NCARDS]) {
    cdhs suit;
    int i, pips;

    for (i = 0; i < 52; ++i) {
        pips = i % 13 + 1;
        if (i < 13)
            suit = clubs;
        else if (i < 26)
            suit = diamonds;
        else if (i < 39)
            suit = hearts;
        else
            suit = spades;
        deck[i] = assign_values(pips, suit);
    }
}

void prn_card_values(card *c_ptr) {
    int pips = c_ptr -> pips;
    cdhs suit = c_ptr -> suit;
    char *suit_name;

    switch (suit) {
    case clubs:
        suit_name = "clubs";
        break;
    case diamonds:
        suit_name = "diamonds";
        break;
    case hearts:
        suit_name = "hearts";
        break;
    case spades:
        suit_name = "spades";
        break;
    }
    printf("card: %2d of %s\n", pips, suit_name);
}

void play_poker(card deck[NCARDS]) {
    int flush_cnt = 0, hand_cnt = 0;
    int i, j;
    card hand[NPLAYERS][5];

    srand(time(NULL));
    for (i = 0; i < NDEALS; ++i) {
        shuffle(deck);
        deal_the_cards(deck, hand);
        for (j = 0; j < NPLAYERS; ++j) {
            ++hand_cnt;
            if (is_flush(hand[j])) {
                ++flush_cnt;
                printf("%s%d\n%s%d\n%s%f\n\n",
                    "      Hand number:  ", hand_cnt,
                    "     Flush number:  ", flush_cnt,
                    "Flush probability:  ",
                    (double) flush_cnt / hand_cnt);
            }
        }
    }
}

void shuffle(card deck[NCARDS]) {
    int i, j;

    for (i = 0; i < 52; ++i) {
        j = rand() % 52;
        swap(&deck[i], &deck[j]);
    }
}

void swap(card *p, card *q) {
    card tmp;

    tmp = *p;
    *p = *q;
    *q = tmp;
}

void deal_the_cards(card deck[NCARDS], card hand[NPLAYERS][5]) {
    int card_cnt = 0, i, j;

    for (j = 0; j < 5; ++j) {
        for (i = 0; i < NPLAYERS; ++i) {
            hand[i][j] = deck[card_cnt++];
        }
    }
}

int is_flush(card h[NHAND]) {
    int i;

    for (i = 1; i < 5; ++i)
        if (h[i].suit != h[0].suit)
            return 0;
    return 1;
}
