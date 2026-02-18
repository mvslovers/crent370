/* SINH.C */
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

  Hyperbolic functions

  SINH(X) = (E**X-E**(-1))/2
  COSH(X) = (E**X+E**(-1))/2

*/

__PDPCLIB_API__ double sinh(double x)
{
    double dexpx;

    dexpx = exp(x);

    return( 0.5 * (dexpx - (1.0/dexpx) ) );
}
