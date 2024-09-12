/* TOUPPER.C */
#include <stddef.h>

extern unsigned short *__isbuf;
extern short *__tolow;
extern short *__toup;

__PDPCLIB_API__ int toupper(int c)
{
    return (__toup[(c)]);
}
