/* ATAN.C */
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

#ifdef atan
#undef atan
#endif
/*

     Because atan(x) is valid for large values of "x" &
     the taylor series converges more slowly for large "X"
     we use the following

     1. Reduce to the first octant by using :-

        atan(-x)=-atan(x),
        atan(1/x)=PI/2-atan(x)

     2. Reduce further so that |x| less than tan(PI/12)

        atan(x)=pi/6+atan((X*sqrt(3)-1)/(x+sqrt(3)))

     3. Then use the taylor series

        atan(x) = x - x**3 + x**5 - x**7
                      ----   ----   ----
                        3      5      7

*/

__PDPCLIB_API__ double atan (double x)
{
    int i;
    double term,answer,work,powx;

/*
  if arg is -ve then we want "-atan(-x)"
*/

    if ( x<0.0 ) return ( -atan(-x) );

/*
 If arg is large we can't calculate
 use atan(1/x)=PI/2-atan(x)
*/

    if ( x > 1.0 ) return ((pi/2) - atan(1.0/x));

/*
 now check for large(ish) x > tan(15) (0.26794919243112)
 if so use atan(x)=pi/6+atan((X*SQRT3-1)/(X+SQRT3))
*/

    if( x > (2.0 - sqrt(3.0)))
    return( (pi/6.0) + atan( ( x * sqrt(3.0)-1.0 ) / (x + sqrt(3.0) ) ) );

/*
*       atan(x) = x - x**3 + x**5 - x**7
*                     ----   ----   ----
*                       3      5      7
*/

    i=1;
    answer=x;
    term = x;
    powx = x;

    while (1)
    {
        work = i;
        powx = 0.0 - powx * x * x;
        term = powx / (work + 2.0);
        if ( answer == (answer + term) )break;
        answer = answer + (term);
        i+=2;
    }

    return(answer);

}
