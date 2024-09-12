/* STRCOLL.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strcoll
#undef strcoll
#endif
__PDPCLIB_API__ int strcoll(const char *s1, const char *s2)
{
    return (strcmp(s1, s2));
}
