#include <stdio.h>
#include <assert.h>

struct complex
{
  int x_real;
  int y_imag;
};

struct complex mult2(struct complex a, struct complex b)
{
  struct complex r;

  r.x_real = a.x_real * b.x_real - a.y_imag * b.y_imag;
  r.y_imag = a.y_imag * b.x_real + a.x_real * b.y_imag;

  printf("\n%d + %di\n\n", r.x_real, r.y_imag);

  return r;
}

struct complex square(struct complex k)
{
  struct complex r;

  r.x_real = (k.x_real * k.x_real) - (k.y_imag * k.y_imag); 
  r.y_imag = 2 * (k.x_real * k.y_imag);

  printf("\n%d + %di\n\n", r.x_real, r.y_imag);

  return r;
}

struct complex add2(struct complex a, struct complex b)
{
  struct complex r;

  r.x_real = a.x_real + b.x_real;
  r.y_imag = a.y_imag + b.y_imag;

  printf("\n%d + %di\n\n", r.x_real, r.y_imag);

  return r;
}

struct complex juliamap(struct complex z, struct complex c)
{
  struct complex r;

  r.x_real = ((z.x_real * z.x_real) - (z.y_imag * z.y_imag) + c.x_real);
  r.y_imag = 2 * z.x_real * z.y_imag + c.y_imag;

  printf("\n%d + %di\n\n", r.x_real, r.y_imag);

  return r;
}

void complex_print(struct complex z)
{
  printf("\nz = %d + %di\n\n", z.x_real, z.y_imag);
}

void test()
{
  struct complex first;
  struct complex second;
  struct complex mt;
  struct complex st;
  struct complex at;
  struct complex jmt;
  struct complex cpt;

  first.x_real = 14;
  first.y_imag = 21;
  second.x_real = 26;
  second.y_imag = 30;

  assert(mult2(first, second).x_real == 364);
  assert(mult2(first, second).y_imag == 630);

  assert(square(first).x_real == 196);
  assert(square(first).y_imag == 441);

  assert(add2(first, second).x_real == 40);
  assert(add2(first, second).y_imag == 51);

  assert(juliamap(first, second).x_real == 663);
  assert(juliamap(first, second).y_imag == 618);
}

int main()
{
  struct complex first;
  struct complex second;

  first.x_real = 14;
  first.y_imag = 21;
  second.x_real = 26;
  second.y_imag = 30;

  mult2(first, second);
  square(first);
  add2(first, second);
  juliamap(first, second);
  complex_print(first);

  return 0;
}
