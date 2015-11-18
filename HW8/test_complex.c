#include <stdio.h>
#include <assert.h>
#include "complex.h"

void test()
{
  COMPLEX first;
  first.x_real = 1;
  first.y_imag = 4;

  COMPLEX second;
  second.x_real = 5;
  second.y_imag = 2;

  COMPLEX *p1;
  p1 = &first;
  
  COMPLEX *p2;
  p2 = &second;


  COMPLEX exm1;
  COMPLEX exm2;

  COMPLEX resm;

  exm1.x_real = -3;
  exm2.y_imag = 22;

  resm = mult2(p1, p2);

  assert(resm.x_real == exm1.x_real);
  assert(resm.y_imag == exm2.y_imag);

  COMPLEX exs1;
  COMPLEX exs2;

  COMPLEX ress;

  exs1.x_real = -15;
  exs2.y_imag = 8;

  ress = square(p1);

  assert(ress.x_real == exs1.x_real);
  assert(ress.y_imag == exs2.y_imag);

  COMPLEX exa1;
  COMPLEX exa2;

  COMPLEX resa;

  exa1.x_real = 6;
  exa2.y_imag = 6;

  resa = add2(p1, p2);

  assert(resa.x_real == exa1.x_real);
  assert(resa.y_imag == exa2.y_imag);

  COMPLEX exjm1;
  COMPLEX exjm2;

  COMPLEX resjm;

  exjm1.x_real = -10;
  exjm2.y_imag = 10;

  resjm = juliamap(p1, p2);

  assert(resjm.x_real == exjm1.x_real);
  assert(resjm.y_imag == exjm2.y_imag);
}

int main()
{
  COMPLEX first;

  first.x_real = 14;
  first.y_imag = 21;

  test();
  complex_print(first);

  return 0;
}
