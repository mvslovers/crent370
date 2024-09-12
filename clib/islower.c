/* ISLOWER.C */
#include <stddef.h>

extern unsigned short *__isbuf;
extern short *__tolow;
extern short *__toup;

__PDPCLIB_API__ int islower(int c)
{
    return (__isbuf[(c)] & 0x0020U);
}
