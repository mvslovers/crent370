/* ASIN.C */
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

#ifdef asin
#undef asin
#endif
/*

   This routines Calculate arcsin(x) & arccos(x).

   Note if "x" is close to "1" the series converges slowly.
   To avoid this we use (sin(x)**2 + cos(x)**2)=1
   and fact cos(x)=sin(x+pi/2)

*/

__PDPCLIB_API__ double asin (double y)
{
    int i;
    double term,answer,work,x,powx,coef;

    x = y;

/*
  if arg is -ve then we want "-asin(-x)"
*/

    if (x <0.0 ) return ( -asin(-x) );

/*
    If arg is > 1.0 we can't calculate
    (note also < -1.0 but previous statement removes this case)
*/
    if ( x > 1.0 )
    {
        errno=EDOM;
        return(HUGE_VAL);
    }

/*
 now check for large(ish) x > 0.6
*/

    if( x > 0.75 )
    {
        x = ( sqrt(1.0 - (x*x) ) );
        return((pi/2.0)-asin(x));
    }

/*
     arcsin(x) = x + 1/2 (x^3/3) + (1/2)(3/4)(x^5/5) +
        (1/2)(3/4)(5/6)(x^7/7) + ...
*/
    i=1;
    answer=x;
    term = 1;
    coef = 1;
    powx = x;

    while (1)
    {
        work = i;
        coef = (coef * work)/(work+1);
        powx = powx * x * x;
        term =  coef * powx / (work + 2.0);
        if ( answer == (answer + term) )break;
        answer = answer + (term);
        i+=2;
    }

    return(answer);
}
