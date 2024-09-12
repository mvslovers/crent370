/* LDEXP.C */
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

__PDPCLIB_API__ double ldexp(double x, int exp)
{
/*
  note this is not so easy for IBM as it uses HEX float
*/
    int bin_exp,hex_exp,adj_exp;
    union dblhex
    {
        double d;
        unsigned short s[4];
    };
    union dblhex split;
/*
    note "X" mauy already have an exponent => extract it
*/
    split.d = frexp(x,&bin_exp);
    bin_exp = bin_exp + exp;  /* add in from caller */
/* need to test for sensible value here */
    hex_exp =  (bin_exp / 4); /* convert back to HEX */
    adj_exp =  bin_exp - (hex_exp * 4);
    if (adj_exp < 0){ hex_exp=hex_exp -1; adj_exp = 4 + adj_exp;}
    split.s[0] = split.s[0] & 0x80ff;
    split.s[0] = split.s[0] | (((hex_exp+64)  << 8) & 0x7f00);
    /* following code adjust for fact IBM has hex float */
    /* well it will I have done */
    while ( adj_exp > 0 )
    {
        split.d = split.d * 2;
        --adj_exp;
    }
    /**/
    return(split.d);
}
