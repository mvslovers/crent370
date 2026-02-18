/* MTXFREE.C */
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "clibmutx.h"
#include "cliblock.h"

void
mtxfree(CLIBMUTX *mutex)
{
    unsigned    *psa    = (unsigned*)0;         /* MVS prefixed save area */
    unsigned    tcb     = psa[0x21C/4];         /* get our TCB address */

    if (mutex->owner != 0) {
        /* someone has this mutex locked, however we're about to free it
        ** so we need to unlock it before we do the deed!
        */
        unlock(mutex,0);
    }

    memset(mutex, 0, sizeof(CLIBMUTX));

    free(mutex);

quit:
    return;
}
