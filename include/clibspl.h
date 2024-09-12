#ifndef CLIBSPL_H

static __inline void *
spl_memset(void *s, int c, size_t n)
{
    __asm__ __volatile__("\n*** SPL_MEMSET ***\n"
"         L     14,%0           => target (s)\n"
"         L     15,%1           => length (n)\n"
"         SLR   0,0             => source (NULL)\n"
"         L     1,%2            fill character\n"
"         SLL   1,24            move fill to high byte\n"
"         MVCL  14,0            Set target to fill character"
    : : "m"(s), "m"(n), "m"(c) : "0", "1", "14", "15");
    return s;
}

static __inline void *
spl_memclr(void *s, size_t n)
{
    __asm__ __volatile__("\n*** SPL_MEMCLR ***\n"
"         L     14,%0           => target (s)\n"
"         L     15,%1           => length (n)\n"
"         SLR   0,0             => source (NULL)\n"
"         SLR   1,1             zero fill\n"
"         MVCL  14,0            Set target to fill character"
    : : "m"(s), "m"(n) : "0", "1", "14", "15");
    return s;
}

static __inline void *
spl_memcpy(void *s1, const void *s2, size_t n)
{
    __asm__ __volatile__("\n*** SPL_MEMCPY ***\n"
"         L    14,%0    => target (s1)\n"
"         L    15,%1    => length (n)\n"
"         L    0,%2     => source (s2)\n"
"         L    1,%1     => length (n)\n"
"         MVCL 14,0     Copy source to target"
    : : "m"(s1), "m"(n), "m"(s2) : "0", "1", "14", "15");

    return (s1);
}

static __inline void *
spl_memcpyp(void *target, int tlen, void *source, int slen, int pad)
{
    __asm__ __volatile__("\n*** SPL_MEMCPYP ***\n"
"         L     14,%0           => target (target)\n"
"         L     15,%1           target length (tlen)\n"
"         L     0,%2            => source (source)\n"
"         L     1,%4            fill character\n"
"         SLL   1,24            move fill to high byte\n"
"         AL    1,%3            source length (slen)\n"
"         MVCL  14,0            Copy source to target"
    : : "m"(target), "m"(tlen), "m"(source), "m"(slen), "m"(pad) : "0", "1", "14", "15");
    return target;
}

static __inline unsigned
spl_strlen(const char *s)
{
    __asm__ __volatile__("\n*** SPL_STRLEN ***");
     const char *p;

    p = s;
    while (*p != '\0') p++;
    return ((unsigned)(p - s));
}

static __inline char *
spl_strcpy(char *s1, const char *s2)
{
    __asm__ __volatile__("\n*** SPL_STRCPY ***");
    char *p = s1;

    while ((*p++ = *s2++) != '\0') ;
    return (s1);
}

static __inline char *
spl_strcpyp(char *target, int tlen, void *source, int pad)
{
     __asm__ __volatile__("\n*** SPL_STRCPYP ***");
    char    *t      = target;
    int     slen    = source ? spl_strlen(source) : 0;

    if (slen > tlen) slen = tlen;

    if (slen > 0) {
        spl_memcpy(t, source, slen);
        t      += slen;
        tlen   -= slen;
    }

    if (tlen > 0) {
        spl_memset(t, pad, tlen);
    }

    return target;
}





#endif /* CLIBSPL_H */
