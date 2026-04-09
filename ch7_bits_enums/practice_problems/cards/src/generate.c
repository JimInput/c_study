#include "cards.h"

suit generate_suit() {
    return (suit) (rand() % N_SUITS);
}

pip generate_pip() {
    return (pip) (rand() % N_PIPS);
}

void generate_card(suit *s, pip *p) {
    *s = generate_suit();
    *p = generate_pip();
}

void generate_hand(suit *suits, pip *pips, int n) {
    uint64_t used = 0;
    
    for (int i = 0; i < n; ++i) {
        suit s;
        pip p;
        int idx;
        
        do {
            s = generate_suit();
            p = generate_pip();
            idx = s*13+p;
        } while (used & (1ULL << idx));

        used |= (1ULL << idx);

        suits[i] = s;
        pips[i] = p;
    }
}