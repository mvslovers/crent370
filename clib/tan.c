/* TAN.C */
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

#ifdef tan
#undef tan
#endif
__PDPCLIB_API__ double tan (double x)
{
/*

  use tan = sin(x)/cos(x)
  if cos(x) is 0 then return HUGE_VAL else return sin/cos

  *** need to set ERROR for overflow ***

*/
    double temp;

    temp=cos(x);
    if (temp == 0.0 )
    {
        /* errno=EDOM; don't seem to return an error here */
        return (HUGE_VAL); /* need to set error here */
    }
    return ( sin(x)/cos(x) );
}
