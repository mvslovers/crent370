/* MEMCPY.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define USE_ASSEMBLER

#ifdef USE_ASSEMBLER
#ifdef memcpy
#undef memcpy
#endif
__PDPCLIB_API__ void *memcpy(void *s1, const void *s2, size_t n)
{
    __asm__("\n"
"         L    14,%0    => target (s1)\n"
"         L    15,%1    => length (n)\n"
"         L    0,%2     => source (s2)\n"
"         L    1,%1     => length (n)\n"
"         MVCL 14,0     Copy source to target"
    : : "m"(s1), "m"(n), "m"(s2) : "0", "1", "14", "15");

    return (s1);
}
#endif  /* USE_ASSEMBLER */

#ifndef USE_ASSEMBLER
#ifdef memcpy
#undef memcpy
#endif
#ifndef __32BIT__
__PDPCLIB_API__ void *memcpy(void *s1, const void *s2, size_t n)
{
    register const unsigned char *f = s2;
    register const unsigned char *fe;
    register unsigned char *t = s1;

    fe = f + n;
    while (f != fe) {
        *t++ = *f++;
    }
    return (s1);
}
#else
__PDPCLIB_API__ void *memcpy(void *s1, const void *s2, size_t n)
{
    register unsigned int *p = (unsigned int *)s1;
    register unsigned int *cs2 = (unsigned int *)s2;
    register unsigned int *endi;

    endi = (unsigned int *)((char *)p + (n & ~0x03));
    while (p != endi) {
        *p++ = *cs2++;
    }

    switch (n & 0x03) {
        case 0:
            break;
        case 1:
            *(char *)p = *(char *)cs2;
            break;
        case 2:
            *(char *)p = *(char *)cs2;
            p = (unsigned int *)((char *)p + 1);
            cs2 = (unsigned int *)((char *)cs2 + 1);
            *(char *)p = *(char *)cs2;
            break;
        case 3:
            *(char *)p = *(char *)cs2;
            p = (unsigned int *)((char *)p + 1);
            cs2 = (unsigned int *)((char *)cs2 + 1);
            *(char *)p = *(char *)cs2;
            p = (unsigned int *)((char *)p + 1);
            cs2 = (unsigned int *)((char *)cs2 + 1);
            *(char *)p = *(char *)cs2;
            break;
    }
    return (s1);
}
#endif /* 32BIT */
#endif /* USE_ASSEMBLER */
