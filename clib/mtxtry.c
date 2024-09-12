/* MTXTRY.C */
#include "clibmutx.h"
#include "cliblock.h"
#include "clibcrt.h"
#include "clibary.h"

int
mtxtry(CLIBMUTX *mutex)
{
    unsigned    *psa    = (unsigned*)0;         /* MVS prefixed save area */
    unsigned    tcb     = psa[0x21C/4];         /* get our TCB address */
    int         rc;

    /* get exclusive control of resource */
    rc = trylock_resf(CLIB_MUTEX_RNAME, 0, mutex);
    if (rc==0 || rc==8) {
        /* we obtained lock(0) or we already had lock(8) */
        mutex->owner = tcb; /* set owner id */
        mutex->count++;     /* increment lock count */
        if (rc==0) {
            /* add mutex to array of mutex's for this thread */
            CLIBCRT *crt    = __crtget();
            arrayadd(&crt->crtmutx, mutex);
        }
        rc = 0;             /* success */
    }

    return rc;
}
