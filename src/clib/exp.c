/* EXP.C */
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

exp(x) = 1 + x + x2/2 + x3/6 + x4/24 + x5/120 + ... + xn/n! + ...

*/
__PDPCLIB_API__ double exp (double x)
{
    int i;
    double term,answer,work;

    i=2;
    term=x;
    answer=x;

    while (1)
    {
        work = i;
        term =  (term * x)/work;
        if ( answer == (answer + term) )break;
        answer = answer + (term);
        i++;
    }

    answer=answer+1.0;
    return(answer);
}
