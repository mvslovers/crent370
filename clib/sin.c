/* SIN.C */
#if 1
#include "math.h"
#include "float.h"
#include "errno.h"
#include "stddef.h"

#if 0
/*

  Some constants to make life easier elsewhere
  (These should I guess be in math.h)

*/
static const double pi   = 3.1415926535897932384626433832795;
static const double ln10 = 2.3025850929940456840179914546844;
static const double ln2 = 0.69314718055994530941723212145818 ;
#else
#define pi      (3.1415926535897932384626433832795)
#define ln10    (2.3025850929940456840179914546844)
#define ln2     (0.69314718055994530941723212145818)
#endif

#else
#include <stddef.h>
#endif

#ifdef sin
#undef sin
#endif
__PDPCLIB_API__ double sin(double x)
{
/*

   Calculate SIN using Taylor series.

   sin(x) = x - x**3  +  x**5  - x**7 + x**9
                ====     ====    ====   ====
                  3!       5!      7!     9!

   Note whilst this is accurate it can be slow for large values
   of "X" so we scale

*/

    int i;
    double term,answer,work,x1;

/*
  scale so series converges pretty quickly
*/
    i = x/(2.0*pi);
    x1 =  x - (i * (2.0 * pi));

/*
 set up initial term
*/
    i=1;
    term=answer=x1;
/*
 loop until no more changes
*/
    while (1)
    {
        work = i+1;
        term = -(term * x1 * x1)/(work * (work + 1.0));
        if ( answer == (answer + term) )break;
        answer = answer + term;
        i = i+2;
    }

    return(answer);
}
