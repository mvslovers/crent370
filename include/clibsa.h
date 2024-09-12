#ifndef SA_H
#define SA_H

#include <clibstr.h>

typedef struct savearea SAVEAREA;
struct savearea {
    unsigned    sa0;        /* 00 */
    unsigned    prev;       /* 04 */
    unsigned    next;       /* 08 */
    unsigned    r14;        /* 0C (12) */
    unsigned    r15;        /* 10 (16) */
    unsigned    r0;         /* 14 (20) */
    unsigned    r1;         /* 18 (24) */
    unsigned    r2;         /* 1C (28) */
    unsigned    r3;         /* 20 (32) */
    unsigned    r4;         /* 24 (36) */
    unsigned    r5;         /* 28 (40) */
    unsigned    r6;         /* 2C (44) */
    unsigned    r7;         /* 30 (48) */
    unsigned    r8;         /* 34 (52) */
    unsigned    r9;         /* 38 (56) */
    unsigned    r10;        /* 3C (60) */
    unsigned    r11;        /* 40 (64) */
    unsigned    r12;        /* 44 (68) */
    unsigned    lws;        /* 48 (72) PL/I language work space */
    unsigned    nab;        /* 4C (76) C next available byte */
};                          /* 50 (80 bytes) */

static __inline SAVEAREA *sa_get(void)
{
    SAVEAREA *sa;

    __asm__("ST     13,%0        return save area address" : "=m"(sa));

    return sa;
}

static __inline SAVEAREA *sa_prev(SAVEAREA *sa)
{
    if (!sa) sa = sa_get();
    return (SAVEAREA*) sa->prev;
}

static __inline SAVEAREA *sa_next(SAVEAREA *sa)
{
    if (!sa) sa = sa_get();
    return (SAVEAREA*) sa->next;
}

static __inline void sa_get_epname(SAVEAREA *sa, char *epname)
{
    void    *ep = (void*) sa->r15;
    char    *p  = (char*) ep;

    epname[0] = 0;

    if (p[0]==0x47 && p[1]==0xF0) {
        p += 4;

        memcpy(epname, p+1, *p);
        epname[*p] = 0;
    }
    else {
        sprintf(epname, "%08X (unknown)", ep);
    }
}

#endif /* SA_H */
