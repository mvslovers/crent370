/* FREXP.C */
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

__PDPCLIB_API__ double frexp(double x, int *exp)
{
/*
  split float into fraction and mantissa
  note this is not so easy for IBM as it uses HEX float
*/
    union dblhex
    {
        double d;
        unsigned short s[4];
    };
    union dblhex split;

    if ( x == 0.0)
    {
        exp=0;
        return (0.0);
    }

    split.d = x;
    *exp = (((split.s[0] >> 8) & 0x007f)-64) * 4;
    split.s[0] = split.s[0] & 0x80ff;
    split.s[0] = split.s[0] | 0x4000;
    /* following code adjust for fact IBM has hex float */
    while ( (fabs(split.d) < 0.5) && (split.d != 0) )
    {
        split.d = split.d * 2;
        *exp =( *exp ) - 1;
    }
    /*    */
    return(split.d);
}
