/* FABS.C */
#if 0
#include "math.h"
#include "float.h"
#include "errno.h"
#include "stddef.h"

/*

  Some constants to make life easier elsewhere
  (These should I guess be in math.h)

*/
static const double pi   = 3.1415926535897932384626433832795;
static const double ln10 = 2.3025850929940456840179914546844;
static const double ln2 = 0.69314718055994530941723212145818 ;
#else
#include <stddef.h>
#endif

#ifdef fabs
#undef fabs
#endif
__PDPCLIB_API__ double fabs(double x)
{
    if (x < 0.0)
    {
        x = -x;
    }
    return (x);
}
