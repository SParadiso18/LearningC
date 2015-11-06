#include <stdio.h>

int main(int argc, char **argv) {

  unsigned long long int n = 0;
  unsigned long long int first = 0;
  unsigned long long int second = 1;
  unsigned long long int next;
  unsigned long long int c;

  printf("%llu\n", first);
  printf("%llu\n", second);

  n = first + second;

  for(c = 0; c < 100 ; c++)
  {
    printf("%llu\n", n);
    first = second;
    second = n;
    n = first + second;
  }

  return 0;
}
