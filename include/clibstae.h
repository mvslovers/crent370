#ifndef CLIBSTAE_H
#define CLIBSTAE_H

#include <clibsdwa.h>

typedef enum {
    ESTAE_CREATE,
    ESTAE_OVERLAY,
    ESTAE_DELETE
} ESTAE_OP;

typedef enum {
    DUMP_SUPPRESS,
    DUMP_DEFAULT,
    DUMP_SNAP,
    DUMP_SDUMP
} DUMP_OP;

#define SETRP(sdwa,rc,retry,regs) \
    ((sdwa)->SDWARCDE=(rc), \
    (sdwa)->SDWARTYA=(retry), \
    (sdwa)->SDWAACF2|=((regs)?SDWAUPRG:0))

extern int __estae(ESTAE_OP op, void *fp, void *udata);
#define estae(op,fp,udata) __estae((op),(fp),(udata))

#ifndef CLIBTRY_H
#include <clibtry.h>
#endif

#endif
