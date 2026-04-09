#include "root.h"

int cnt = 0;
const dbl eps = 1e-15;
const dbl e = 0.5;
const dbl m = 2.2;
const dbl t = 1.0;
const dbl c = 2.0;

int main(void) {
    dbl a = -100.0;
    dbl b = 100.0;
    dbl root;
    int begin_cnt;
    pfdd F[] = {NULL, f, kepler, line};
    size_t sz = sizeof(F) / sizeof(pfdd);
    for (int i = 1; i < sz; ++i) {
        assert(F[i](a)*F[i](b) < 0.0);
        begin_cnt = cnt;
        root = bisection(F[i], a, b);
        printf("%s%d\n%s%.15f\n%s%.15f\n",
        "No. of fct calls: ", cnt - begin_cnt,
        "Approximate root: ", root,
        "  Function value: ", F[i](root));

    }
    return 0;
}