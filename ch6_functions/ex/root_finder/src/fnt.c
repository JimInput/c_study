#include "root.h"

dbl f(dbl x) {
    return pow(x, 7) - 7*x - 3;
}

dbl line(dbl x) {
    return t*x + c;
}

dbl kepler(dbl x) {
    return x - e*sin(x) - m;
}