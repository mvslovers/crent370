/* SQRT.C */
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

#ifdef sqrt
#undef sqrt
#endif
/*

   pretty tivial code here.

     1) Scale x such that 1 <= x <= 4.0

     2) Use newton Raphson to calculate root.

     4) multiply back up.

   Because we only scale by "4" this is pretty slow....

*/

__PDPCLIB_API__ double sqrt(double x)
{
    double xs,yn,ynn;
    double pow1;
    int i;

    if (x < 0.0)
    {
        errno=EDOM;
        return(0.0);
    }
    if (x == 0.0) return (0.0);

/*

  Scale argument 1 <= x <= 4

*/

    xs=x;
    pow1=1;

    while(xs<1.0){xs=xs*4.0;pow1=pow1/2.0;}
    while(xs>=4.0){xs=xs/4.0;pow1=pow1*2.0;}

/*
  calculate using Newton raphson
  use x0 = x/2.0
*/

    i=0;
    yn = xs/2.0;
    ynn = 0;
    while(1)
    {
        ynn = (yn + xs/yn)*0.5;
        if ( fabs(ynn-yn) <= 10.0 * DBL_MIN ) break; else yn=ynn;
        if ( i > 10  ) break; else i++ ;
    }
    return (ynn*pow1);
}
