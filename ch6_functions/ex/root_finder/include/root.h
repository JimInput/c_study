#ifndef ROOT_H
#define ROOT_H

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef double dbl;
typedef dbl (*pfdd)(dbl);

extern int cnt;
extern const dbl eps;
extern const dbl e; //parameter for the Kepler eqn
extern const dbl m; //parameter for the Kepler eqn
extern const dbl t;
extern const dbl c;

dbl bisection(pfdd f, dbl a, dbl b);
dbl f(dbl x);
dbl kepler(dbl x);
dbl line(dbl x);

#endif