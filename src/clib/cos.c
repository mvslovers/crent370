/* COS.C */
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

#ifdef cos
#undef cos
#endif
__PDPCLIB_API__ double cos(double x)
{
/*

   Calculate COS using Taylor series.

   sin(x) = 1 - x**2  +  x**4  - x**6 + x**8
                ====     ====    ====   ====    .........
                  2!       4!      6!     8!

   Note whilst this is accurate it can be slow for large
   values of "X" so we scale

*/

    int i;
    double term,answer,work,x1;

/*
    Scale arguments to be in range 1 => pi
*/

    i = x/(2*pi);
    x1 =  x - (i * (2.0 * pi));

    i=1;
    term=answer=1;


    while (1)
    {
        work = i;
        term = -(term * x1 * x1)/(work * (work + 1.0));
        if ( answer == (answer + term) )break;
        answer = answer + term;
        i += 2;
    }

    return(answer);

}
