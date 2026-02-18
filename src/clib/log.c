/* LOG.C */
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

/*

   Calculate LOG using Taylor series.

   log(1+ x) = x - x**2  +  x**3  - x**4 + x**5
                   ====     ====    ====   ====    .........
                    2         3       4     8

   Note this only works for small x so we scale....

*/
__PDPCLIB_API__ double log (double x)
{
    int i,scale;
    double term,answer,work,xs;

    if (x <= 0 )
    {
        /* need to set signal */
        errno=EDOM;
        return (HUGE_VAL);
    }
    if( x == 1.0)return(0.0);

/*
  Scale arguments to be in range 1 < x <= 10
*/

/*
    scale = 0;
    xs = x;
    while ( xs > 10.0 ) { scale ++; xs=xs/10.0;}
    while ( xs < 1.0 ) { scale --; xs=xs*10.0;}
*/
    xs = frexp(x,&scale);
    xs = (1.0 * xs) - 1.0;
    scale = scale - 0;

    i=2;
    term=answer=xs;

    while (1)
    {
        work = i;
        term = - (term * xs);
        if ( answer == (answer + (term/work)) )break;
        answer = answer + (term/work);
        i++;
    }

    answer = answer + (double)scale * ln2;
    return(answer);
}
