/* ACOS.C */
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

#ifdef acos
#undef acos
#endif
/*

  For cos just use (sin(x)**2 + cos(x)**2)=1
  Note:- asin(x) decides which taylor series
  to use to ensure quickest convergence.

*/
__PDPCLIB_API__ double acos(double x)
{

/*
*/

    if ( fabs(x) > 1.0 ) /* is argument out of range */
    {
        errno=EDOM;
        return (HUGE_VAL);
    }
    if ( x < 0.0 ) return ( pi - acos(-x) ) ;

    return ( asin ( sqrt(1.0 - x*x) ) );

}
