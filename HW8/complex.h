#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct complex
{
    long double x_real;
    long double y_imag;
};

typedef struct complex COMPLEX;

COMPLEX mult2(const COMPLEX *a, const COMPLEX *b);
COMPLEX square(const COMPLEX *k);
COMPLEX add2(const COMPLEX *a, const COMPLEX *b);
COMPLEX juliamap(const COMPLEX *z, const COMPLEX *c);
void complex_print(COMPLEX z);
void test();
