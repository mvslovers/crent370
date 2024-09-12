/* POW.C */
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

   This code uses log and exp to calculate x to the power y.
   If

*/

__PDPCLIB_API__ double pow(double x,double y)
{
    int j,neg;
    double yy,xx;
    neg=0;
    j=y;
    yy=j;
    if( yy == y) {
        xx = x;
        if ( y < 0 ){neg = 1; j = -j;}
        if ( y == 0) return (1.0);
        --j;
        while(j>0){ xx=xx * x; j--;}
        if(neg)xx=1.0/xx;
        return (xx);
    }
    if (x < 0.0)
    {
         errno=EDOM;
         return(0.0);
    }
    if (y == 0.0) return (1.0);

    return (exp(y*log(x)));
}
