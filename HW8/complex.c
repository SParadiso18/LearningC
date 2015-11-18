#include <stdio.h>
#include <assert.h>
#include "complex.h"

COMPLEX mult2(const COMPLEX *a, const COMPLEX *b)
{
  COMPLEX r;

  r.x_real = a->x_real * b->x_real - a->y_imag * b->y_imag;
  r.y_imag = a->y_imag * b->x_real + a->x_real * b->y_imag;

  printf("\n%.2Lf + %.2Lfi\n\n", r.x_real, r.y_imag);

  return r;
}

COMPLEX square(const COMPLEX *k)
{
  COMPLEX r;

  r.x_real = (k->x_real * k->x_real) - (k->y_imag * k->y_imag); 
  r.y_imag = 2 * (k->x_real * k->y_imag);

  printf("\n%.2Lf + %.2Lfi\n\n", r.x_real, r.y_imag);

  return r;
}

COMPLEX add2(const COMPLEX *a, const COMPLEX *b)
{
  COMPLEX r;

  r.x_real = a->x_real + b->x_real;
  r.y_imag = a->y_imag + b->y_imag;

  printf("\n%.2Lf + %.2Lfi\n\n", r.x_real, r.y_imag);

  return r;
}

COMPLEX juliamap(const COMPLEX *z, const COMPLEX *c)
{
  COMPLEX r;

  r.x_real = ((z->x_real * z->x_real) - (z->y_imag * z->y_imag) + c->x_real);
  r.y_imag = 2 * z->x_real * z->y_imag + c->y_imag;

  printf("\n%.2Lf + %.2Lfi\n\n", r.x_real, r.y_imag);

  return r;
}

void complex_print(COMPLEX z)
{
  printf("\nz = %.2Lf + %.2Lfi\n\n", z.x_real, z.y_imag);
}
