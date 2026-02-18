/* MEMSET.C */
#include <stdio.h>
// #include <string.h>
#include <stddef.h>

#define USE_ASSEMBLER

#ifdef USE_ASSEMBLER
#ifdef memset
#undef memset
#endif
__PDPCLIB_API__ void *memset(void *s, int c, size_t n)
{
    __asm__("\n"
"         L    14,%0    => target (s)\n"
"         L    15,%1    => length (n)\n"
"         SLR  0,0      => source (NULL)\n"
"         L    1,%2     => fill (c)\n"
"         SLL  1,24     move fill char to high byte\n"
"         MVCL 14,0     Set target to fill character"
    : : "m"(s), "m"(n), "m"(c) : "0", "1", "14", "15");

    return (s);
}
#endif  /* USE_ASSEMBLER */


#ifndef USE_ASSEMBLER
#ifdef memset
#undef memset
#endif
__PDPCLIB_API__ void *memset(void *s, int c, size_t n)
{
    size_t x = 0;

    for (x = 0; x < n; x++) {
        *((char *)s + x) = (unsigned char)c;
    }
    return (s);
}
#endif
