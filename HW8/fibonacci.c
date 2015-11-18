/********************************************
*   I was able to solve the negative values *
* in the initial submission of the          *
* Fibonacci assignment. I found that these  *
* values would arise due to 'integer        *
* overflow'. This occurs when trying to     *
* store excessively large values as         *
* integers which can only contain 32 bit    *
* values. When comparing to an online       *
* Fibonacci source I believe it was around  *
* the 47th or so value of the series that   *
* showed the first incorrect value.         *
*   With this information in mind, I        *
* altered the declared types to             *
* 'unassigned long long int' as can be      *
* seen in the initial submission.           *
*   Here, we have the desired 'long double' *
* which again displays the values we had    *
* origionaly but probably with more         *
* efficient memory allocation.              *
********************************************/

#include <stdio.h>

int main(int argc, char **argv) {

  long double n = 0;
  long double first = 1;
  long double second = 1;
  long double c;

  printf("%.0Lf\n", first);
  printf("%.0Lf\n", second);

  n = first + second;

  for(c = 0; c < 100 ; c++)
  {
    printf("%.0Lf\n", n);
    first = second;
    second = n;
    n = first + second;
  }

  printf("\n");

  return 0;
}
