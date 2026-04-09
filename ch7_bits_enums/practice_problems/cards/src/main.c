#include "cards.h"

#define N 5
int main(void) {
    srand(time(NULL));

    suit s[N];
    pip p[N];

    generate_hand(s, p, N);

    print_hand(s, p, N);

    return 0;
}