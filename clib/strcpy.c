/* STRCPY.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strcpy
#undef strcpy
#endif
__PDPCLIB_API__ char *strcpy(char *s1, const char *s2)
{
    char *p = s1;

    while ((*p++ = *s2++) != '\0') ;
    return (s1);
}
