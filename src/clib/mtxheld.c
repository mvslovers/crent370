/* MTXHELD.C */
#include "clibmutx.h"
#include "cliblock.h"

int
mtxheld(CLIBMUTX *mutex)
{
    unsigned    *psa    = (unsigned*)0;         /* MVS prefixed save area */
    unsigned    tcb     = psa[0x21C/4];         /* get our TCB address */

    /* return true if we have a lock on this mutex */
    return (mutex->count != 0 && mutex->owner == tcb);
}
