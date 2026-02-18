/* MTXNHELD.C */
#include "clibmutx.h"
#include "cliblock.h"

int
mtxnheld(CLIBMUTX *mutex)
{
    unsigned    *psa    = (unsigned*)0;         /* MVS prefixed save area */
    unsigned    tcb     = psa[0x21C/4];         /* get our TCB address */

    /* return true if mutex is unlocked or locked by another thread */
    return (mutex->count == 0 || mutex->owner != tcb);
}
